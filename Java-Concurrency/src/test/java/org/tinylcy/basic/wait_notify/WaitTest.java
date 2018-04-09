package org.tinylcy.basic.wait_notify;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class WaitTest {

    @Test
    public void testWait() {
        ThreadA t = new ThreadA("t");

        /**
         * https://stackoverflow.com/questions/2779484/why-must-wait-always-be-in-synchronized-block
         */
        synchronized (this.getClass()) {
            try {
                System.out.println(Thread.currentThread().getName() + " start t");
                t.start();

                System.out.println(Thread.currentThread().getName() + " wait_notify()");
                t.wait();

                System.out.println(Thread.currentThread().getName() + " continue");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    @Test
    public void testWaitSomeTime() {
        ThreadB t1 = new ThreadB();
        synchronized (t1) {
            try {
                System.out.println(Thread.currentThread().getName() + " start t1");
                t1.start();

                System.out.println(Thread.currentThread().getName() + " wait_notify()");
                t1.wait(2000);

                System.out.println(Thread.currentThread().getName() + " continue");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


    @Test
    public void testNotifyAll() {
        Object lock = new Object();
        ThreadC t1 = new ThreadC(lock);
        ThreadC t2 = new ThreadC(lock);
        ThreadC t3 = new ThreadC(lock);
        t1.start();
        t2.start();
        t3.start();

        try {
            System.out.println(Thread.currentThread().getName() + " sleep(3000)");
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        synchronized (lock) {
            System.out.println(Thread.currentThread().getName() + " notifyAll()");
            lock.notifyAll();
        }
    }
}
