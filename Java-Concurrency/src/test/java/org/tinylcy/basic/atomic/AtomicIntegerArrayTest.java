package org.tinylcy.basic.atomic;

import org.junit.Test;

import java.util.concurrent.atomic.AtomicIntegerArray;

import static org.junit.Assert.*;

/**
 * Created by tinylcy.
 */
public class AtomicIntegerArrayTest {

    @Test
    public void testAtomicIntegerArray() {
        AtomicIntegerArray aia = new AtomicIntegerArray(new int[]{1, 2, 3, 4, 5});
        aia.set(0, 5);
        assertEquals(aia.getAndDecrement(0), 5);
        assertEquals(aia.decrementAndGet(1), 1);
        assertEquals(aia.getAndIncrement(2), 3);
        assertEquals(aia.incrementAndGet(3), 5);
        assertEquals(aia.addAndGet(0, 10), 14);
        assertEquals(aia.getAndAdd(1, 10), 1);
    }
}
