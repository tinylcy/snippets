package org.tinylcy.basic.lock;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class AtomicIntegerWIthLockTest {

    @Test
    public void testAtomicIntegerWithLock() throws InterruptedException {
        int max = 10;
        final int loopCount = 100000;
        long start = System.nanoTime();

        final AtomicIntegerWithLock value1 = new AtomicIntegerWithLock(0);
        Thread[] ts = new Thread[max];
        for (int i = 0; i < max; i++) {
            ts[i] = new Thread() {
                @Override
                public void run() {
                    for (int j = 0; j < loopCount; j++) {
                        value1.incrementAndGet();
                    }
                    System.out.println(Thread.currentThread().getName() + " loopCount is " + loopCount + ", value is " + value1.get());
                }
            };
        }

        for (Thread t : ts) {
            t.start();
        }

        for (Thread t : ts) {
            t.join();
        }

        long end = System.nanoTime();
        System.out.println("Cost time: " + (end - start));
    }
}
