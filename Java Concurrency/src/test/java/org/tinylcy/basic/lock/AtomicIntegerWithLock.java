package org.tinylcy.basic.lock;

import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

/**
 * Created by tinylcy.
 */
public class AtomicIntegerWithLock {

    private int value;
    private Lock lock = new ReentrantLock();

    public AtomicIntegerWithLock(int value) {
        this.value = value;
    }

    public int get() {
        lock.lock();
        try {
            return value;
        } finally {
            lock.unlock();
        }
    }

    public void set(int value) {
        lock.lock();
        try {
            this.value = value;
        } finally {
            lock.unlock();
        }
    }

    public int incrementAndGet() {
        lock.lock();
        try {
            value += 1;
            return value;
        } finally {
            lock.unlock();
        }
    }

}
