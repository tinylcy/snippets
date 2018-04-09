package org.tinylcy.basic.cas;

/**
 * Created by tinylcy.
 */
public class SimulateCAS {

    private volatile int value;

    public int getValue() {
        return value;
    }

    /**
     * 模拟 unsafe 的原子指令
     *
     * @param expect
     * @param newValue
     * @return
     */
    public boolean compareAndSet(int expect, int newValue) {
        synchronized (this) {
            if (value == expect) {
                value = newValue;
                return true;
            }
        }

        return false;
    }
}
