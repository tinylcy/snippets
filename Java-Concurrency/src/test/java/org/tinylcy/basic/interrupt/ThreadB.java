package org.tinylcy.basic.interrupt;

/**
 * Created by tinylcy.
 */
public class ThreadB extends Thread {

    public ThreadB(String name) {
        super(name);
    }

    @Override
    public void run() {
        int i = 0;
        while (!isInterrupted()) {
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(Thread.currentThread().getName() + " (" + this.getState() + ") catch InterruptedException.");
            }

            i++;
            System.out.println(Thread.currentThread().getName() + " (" + getState() + ") loop, i = " + i);
        }
    }
}
