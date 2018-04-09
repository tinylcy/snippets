package org.tinylcy.basic.thread;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class ThreadTest {

    @Test
    public void testThread() {
        MyThread t1 = new MyThread();
        MyThread t2 = new MyThread();
        MyThread t3 = new MyThread();

        t1.start();
        t2.start();
        t3.start();
    }

    @Test
    public void testTwice() {
        MyThread t1 = new MyThread();
        t1.start();
//        t1.start(); // IllegalThreadStateEException
    }

}
