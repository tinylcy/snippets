package org.tinylcy.basic.wait_notify;

/**
 * Created by tinylcy.
 */
public class ThreadB extends Thread {

    @Override
    public void run() {
        System.out.println(Thread.currentThread().getName() + " run");
        while (true) {

        }
    }

}
