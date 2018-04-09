package org.tinylcy.basic.sleep;

import org.junit.Test;

/**
 * Created by tinylcy.
 */
public class SleepTest {

    /**
     * sleep 和 wait 的比较
     * 1. wait 让当前线程从 “运行状态” 进入 “等待（阻塞）状态” 的同时,也会释放同步锁.
     * 2. sleep 的作用是让当前线程从 “运行状态” 进入到 “休眠（阻塞）状态”, 不会释放锁.
     *
     * @throws InterruptedException
     */
    @Test
    public void testSleepLock() throws InterruptedException {
        Object lock = new Object();
        ThreadA t1 = new ThreadA("t1", lock);
        ThreadA t2 = new ThreadA("t2", lock);

        t1.start();
        t2.start();

        t1.join();
        t2.join();
    }
}
