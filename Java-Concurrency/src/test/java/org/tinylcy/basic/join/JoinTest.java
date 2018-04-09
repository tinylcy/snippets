package org.tinylcy.basic.join;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class JoinTest {

    @Test
    public void testJoin() throws InterruptedException {
        ThreadA t1 = new ThreadA("t1");
        t1.start();
        t1.join();
        System.out.println(Thread.currentThread().getName() + " finished.");
    }
}
