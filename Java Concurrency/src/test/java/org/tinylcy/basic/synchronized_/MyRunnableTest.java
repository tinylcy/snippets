package org.tinylcy.basic.synchronized_;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class MyRunnableTest {

    @Test
    public void testSynchronized() throws InterruptedException {
        Runnable runnable= new MyRunnable();
        Thread t1 = new Thread(runnable);
        Thread t2 = new Thread(runnable);
        t1.start();
        t2.start();

        Thread.sleep(2000);
    }
}
