package org.tinylcy.annotation;

import java.lang.annotation.Annotation;
import java.lang.reflect.Method;

/**
 * Created by tinylcy.
 */
public class RunTest {

    public static void main(String[] args) {
        System.out.println("Testing...");

        int passed = 0, failed = 0, count = 0, ignored = 0;

        Class<TestExample> obj = TestExample.class;

        // Process @TesterInfo
        if (obj.isAnnotationPresent(TesterInfo.class)) {
            Annotation annotation = obj.getAnnotation(TesterInfo.class);
            TesterInfo testerInfo = (TesterInfo) annotation;

            System.out.println("Priority: " + testerInfo.priority());
            System.out.println("CreatedBy: " + testerInfo.createdBy());
            System.out.println("Tags: " + testerInfo.tags());

            int tagLength = testerInfo.tags().length;
            for (String tag : testerInfo.tags()) {
                System.out.println(tag + " ");
            }

            System.out.println("Last Modified: " + testerInfo.lastModified());
        }

        // Process @Test
        for (Method method : obj.getDeclaredMethods()) {
            // If method is annotated with @Test
            if (method.isAnnotationPresent(Test.class)) {
                Annotation annotation = method.getAnnotation(Test.class);
                Test test = (Test) annotation;

                // If enable = true (default)
                if (test.enabled()) {
                    try {
                        method.invoke(obj.newInstance());
                        System.out.println(++count + " - Test " + method.getName() + " - passed ");
                        passed++;
                    } catch (Exception e) {
                        System.out.println(++count + " - Test " + method.getName() + " - failed " + e.getCause());
                        failed++;
                    }
                } else {
                    System.out.println(++count + " - Test " + method.getName() + " - ignored");
                    ignored++;
                }
            }
        }
        System.out.println("Result - Total: " + count + ", Passed: " + passed + ", Failed: " + failed + ", Ignored: " + ignored);
    }

}
