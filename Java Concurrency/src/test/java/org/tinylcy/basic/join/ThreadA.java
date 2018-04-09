package org.tinylcy.basic.join;

/**
 * Created by tinylcy.
 */
public class ThreadA extends Thread {

    public ThreadA(String name) {
        super(name);
    }

    @Override
    public void run() {
        System.out.println(getName() + " started.");

        for (int i = 0; i < 1000000; i++) {
        }

        System.out.println(getName() + " finished.");
    }
}
