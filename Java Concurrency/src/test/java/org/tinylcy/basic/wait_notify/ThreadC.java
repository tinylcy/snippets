package org.tinylcy.basic.wait_notify;

/**
 * Created by tinylcy.
 */
public class ThreadC extends Thread {

    private Object lock;

    public ThreadC(Object lock) {
        this.lock = lock;
    }

    @Override
    public void run() {
        synchronized (lock) {
            try {
                System.out.println(Thread.currentThread().getName() + " wait");
                lock.wait();

                System.out.println(Thread.currentThread().getName() + " continue");
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
