package org.tinylcy.basic.runnable;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class RunnableTest {

    @Test
    public void testRunnable() {
        org.tinylcy.basic.runnable.MyThread mt = new MyThread();
        Thread t1 = new Thread(mt);
        Thread t2 = new Thread(mt);
        Thread t3 = new Thread(mt);

        t1.start();
        t2.start();
        t3.start();

    }
}
