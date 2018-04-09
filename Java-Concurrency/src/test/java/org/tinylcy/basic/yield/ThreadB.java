package org.tinylcy.basic.yield;

/**
 * Created by tinylcy.
 */
public class ThreadB extends Thread {

    private Object lock;

    public ThreadB(String name, Object lock) {
        super(name);
        this.lock = lock;
    }

    @Override
    public void run() {
        synchronized (lock) {
            for (int i = 0; i < 10; i++) {
                System.out.println(getName() + " priority: " + getPriority() + " i: " + i);
                if (i % 4 == 0) {
                    Thread.yield();
                }
            }
        }
    }
}
