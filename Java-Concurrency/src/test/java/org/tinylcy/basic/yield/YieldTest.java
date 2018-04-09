package org.tinylcy.basic.yield;

import org.junit.Test;

/**
 * Created by tinylcy.
 * <p>
 * yield 的作用是同步,它能让当前线程从 “运行状态” 进入到 “就绪状态”,从而让其他具有相同优先级的等待线程获得执行权;
 * 但是,并不能保证在当前线程调用 yield 之后,其他具有相同优先级的线程就一定能获得执行权;也有可能是当前线程又进入到
 * “运行状态” 继续运行.
 */
public class YieldTest {

    @Test
    public void testYield() throws InterruptedException {
        ThreadA t1 = new ThreadA("t1");
        ThreadA t2 = new ThreadA("t2");

        t1.start();
        t2.start();

        Thread.sleep(1000);
    }

    /**
     * yield 和 wait 的比较
     * 1. wait 让线程从 “运行状态” 进入到 “阻塞状态”, yield 让线程从 “运行状态” 进入到 “就绪状态”.
     * 2. wait 会让线程释放它所持有对象的同步锁, yield 不会释放锁.
     *
     * @throws InterruptedException
     */
    @Test
    public void testYieldLock() throws InterruptedException {
        Object lock = new Object();
        ThreadB t1 = new ThreadB("t1", lock);
        ThreadB t2 = new ThreadB("t2", lock);

        t1.start();
        t2.start();

        Thread.sleep(1000);
    }
}
