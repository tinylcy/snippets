package org.tinylcy.basic.atomic;

import org.junit.Test;

import java.util.concurrent.atomic.AtomicIntegerFieldUpdater;

import static org.junit.Assert.*;

/**
 * Created by tinylcy.
 * <p>
 * 字段的原子更新.
 * <p>
 * 相应的 API 非常简单,但是也有一些约束.
 * （1）字段必须是 volatile 的.
 * （2）字段的描述类型（修饰符public/protected/default/private）是与调用者与操作对象字段的关系一致.也就是
 * 说调用者可以直接操作对象字段,那么就可以通过反射进行原子操作.但是对于父类的字段,子类是不能直接操作的,尽管子类可以访问父类的字段.
 * （3）只能是实例变量,不能是类变量,即不能加 static 关键字.
 * （4）只能是可修改变量,不能是 final 变量.
 * （5）对于 AtomicIntegerFieldUpdater 和 AtomicLongFieldUpdater,只能修改 int/long 类型的字段,不能修改其包装类型 Integer/Long.
 * 如果要修改包装类型需要使用 AtomicReferenceFieldUpdater.
 */
public class AtomicIntegerFieldUpdaterTest {

    private class DemoData {
        public volatile int value1 = 1;
        volatile int value2 = 2;
        protected volatile int value3 = 3;
        private volatile int value4 = 4;
    }

    AtomicIntegerFieldUpdater<DemoData> getUpdater(String fieldName) {
        return AtomicIntegerFieldUpdater.newUpdater(DemoData.class, fieldName);
    }

    @Test
    public void testAtomicIntegerFieldUpdater() {
        DemoData data = new DemoData();
        assertEquals(getUpdater("value1").getAndSet(data, 10), 1);
        assertEquals(getUpdater("value2").incrementAndGet(data), 3);
        assertEquals(getUpdater("value3").decrementAndGet(data), 2);
//        assertTrue(getUpdater("value4").compareAndSet(data, 4, 5));
    }
}
