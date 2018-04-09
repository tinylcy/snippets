package org.tinylcy.basic.synchronized_;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class PerformanceTest {

    public synchronized void syncMethod() {

    }

    public void syncBlock() {
        synchronized (this) {

        }
    }

    @Test
    public void testSyncMethod() {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 1000000; i++) {
            syncMethod();
        }
        long end = System.currentTimeMillis();
        System.out.println("time used: " + (end - start));
    }

    @Test
    public void testSyncBlock() {
        long start = System.currentTimeMillis();
        for (int i = 0; i < 1000000; i++) {
            syncBlock();
        }
        long end = System.currentTimeMillis();
        System.out.println("time used: " + (end - start));
    }
}
