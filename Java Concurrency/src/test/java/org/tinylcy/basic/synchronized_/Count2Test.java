package org.tinylcy.basic.synchronized_;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class Count2Test {

    @Test
    public void testCount2() throws InterruptedException {
        final Count2 count = new Count2();

        Thread t1 = new Thread(new Runnable() {
            public void run() {
                count.syncMethod1();
            }
        });

        Thread t2 = new Thread(new Runnable() {
            public void run() {
                count.syncMethod2();
            }
        });

        t1.start();
        t2.start();

        Thread.sleep(2000);
    }
}
