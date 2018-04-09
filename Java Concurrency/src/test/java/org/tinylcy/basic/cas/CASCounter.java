package org.tinylcy.basic.cas;

import org.junit.Test;

import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

/**
 * Created by tinylcy.
 */
public class CASCounter {

    private SimulateCAS simulateCAS;

    public CASCounter() {
        this.simulateCAS = new SimulateCAS();
    }

    public int getCounter() {
        return simulateCAS.getValue();
    }

    public int incrementAndGet() {
        int value;
        int newValue;

        do {
            value = simulateCAS.getValue();
            newValue = value + 1;
        } while (!simulateCAS.compareAndSet(value, newValue));

        return newValue;
    }

    @Test
    public void testCAS() throws InterruptedException {
        ExecutorService service = Executors.newFixedThreadPool(30);
        final CASCounter casCounter = new CASCounter();
        for (int i = 0; i < 10000; i++) {
            service.submit(new Callable<Object>() {
                public Object call() throws Exception {
                    return casCounter.incrementAndGet();
                }
            });
        }

        service.shutdown();
        service.awaitTermination(1, TimeUnit.MINUTES);
        System.out.println(casCounter.getCounter());
    }
}
