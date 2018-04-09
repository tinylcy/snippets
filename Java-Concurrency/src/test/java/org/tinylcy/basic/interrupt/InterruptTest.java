package org.tinylcy.basic.interrupt;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class InterruptTest {

    @Test
    public void testInterrupt1() {
        try {

            ThreadA t1 = new ThreadA("t1");
            System.out.println(t1.getName() + " (" + t1.getState() + ") is new.");

            t1.start();
            System.out.println(t1.getName() + " (" + t1.getState() + ") is started.");

            Thread.sleep(300);
            t1.interrupt();
            System.out.println(t1.getName() + " (" + t1.getState() + ") is interrupted.");

            Thread.sleep(300);
            System.out.println(t1.getName() + " (" + t1.getState() + ") is interrupted now.");

        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }


    /**
     * 程序进入死循环.
     * 原因:
     * 调用 interrupt() 会立即将线程的中断标记设为 true,但是由于线程出于阻塞状态,所以该中断标记
     * 会被清除为 false,同时,会产生一个 InterruptException 异常.
     */
    @Test
    public void testInterrupt2() {
        try {

            ThreadB t1 = new ThreadB("t1");
            System.out.println(t1.getName() + " (" + t1.getState() + ") is new.");

            t1.start();
            System.out.println(t1.getName() + " (" + t1.getState() + ") is started.");

            Thread.sleep(300);
            t1.interrupt();
            System.out.println(t1.getName() + " (" + t1.getState() + ") is interrupted.");

            Thread.sleep(300);
            System.out.println(t1.getName() + " (" + t1.getState() + ") is interrupted now.");

            t1.join();

        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
