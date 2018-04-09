package org.tinylcy.basic.synchronized_;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class CountTest {

    @Test
    public void testCount() throws InterruptedException {
        final Count count = new Count();

        Thread t1 = new Thread(new Runnable() {
            public void run() {
                count.syncMethod();
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                count.nonSyncMethod();
            }
        });

        t1.start();
        t2.start();

        Thread.sleep(2000);
    }
}
