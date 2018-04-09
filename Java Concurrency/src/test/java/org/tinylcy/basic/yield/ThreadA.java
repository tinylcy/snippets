package org.tinylcy.basic.yield;

/**
 * Created by tinylcy.
 */
public class ThreadA extends Thread {

    public ThreadA(String name) {
        super(name);
    }

    @Override
    public synchronized void run() {
        for (int i = 0; i < 10; i++) {
            System.out.println(getName() + " priority: " + getPriority() + " i: " + i);
            if (i % 4 == 0) {
                Thread.yield();
            }
        }
    }
}
