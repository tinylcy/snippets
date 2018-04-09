package org.tinylcy.basic.thread;

/**
 * Created by tinylcy.
 */
public class MyThread extends Thread {

    private int ticket = 10;

    @Override
    public void run() {
        for (int i = 0; i < 20; i++) {
            if(ticket > 0) {
                System.out.println(this.getName() + " sold ticket: " + ticket--);
            }
        }
    }
}
