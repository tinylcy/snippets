package org.tinylcy.basic.runnable;

/**
 * Created by tinylcy.
 */
public class MyThread implements Runnable {

    private int ticket = 100;

    public void run() {
        for (int i = 0; i < 200; i++) {
            if (ticket > 0) {
                System.out.println(Thread.currentThread().getName() + " sold ticket: " + ticket--);
            }
        }
    }
}
