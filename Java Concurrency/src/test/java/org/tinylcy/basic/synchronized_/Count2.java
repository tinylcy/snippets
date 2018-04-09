package org.tinylcy.basic.synchronized_;

/**
 * Created by tinylcy.
 */
public class Count2 {

    public void syncMethod1() {
        synchronized (this) {
            try {
                for (int i = 0; i < 5; i++) {
                    Thread.sleep(100);
                    System.out.println(Thread.currentThread().getName() + " syncMethod1 loop " + i);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }

    public void syncMethod2() {
        synchronized (this) {
            try {
                for (int i = 0; i < 5; i++) {
                    Thread.sleep(100);
                    System.out.println(Thread.currentThread().getName() + " syncMethod2 loop " + i);
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
