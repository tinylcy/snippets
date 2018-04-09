package org.tinylcy.basic.sleep;

/**
 * Created by tinylcy.
 */
public class ThreadA extends Thread {

    private Object lock;

    public ThreadA(String name, Object lock) {
        super(name);
        this.lock = lock;
    }

    @Override
    public void run() {
        synchronized (lock) {
            try {
                for (int i = 0; i < 10; i++) {
                    System.out.println(getName() + " priority: " + getPriority() + " i: " + i);
                    if (i % 4 == 0) {
                        Thread.sleep(100);
                    }
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
