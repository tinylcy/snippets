package org.tinylcy.basic.atomic;

import org.junit.Test;

import java.util.concurrent.atomic.AtomicReference;

/**
 * Created by tinylcy.
 */
public class AtomicReferenceTest {

    private class Student {
        volatile long id;

        public Student(long id) {
            this.id = id;
        }

        @Override
        public String toString() {
            return "Student id = " + id;
        }
    }

    @Test
    public void testAtomicReference() {
        Student s1 = new Student(1);
        Student s2 = new Student(2);
        AtomicReference<Student> ar = new AtomicReference<Student>(s1);
        ar.compareAndSet(s1, s2);
        Student s3 = ar.get();

        System.out.println("s3 is " + s3);
        System.out.println("s3.equals(s1) = " + s3.equals(s1));
    }
}
