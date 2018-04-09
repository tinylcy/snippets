package org.tinylcy.basic.wait_notify;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Created by tinylcy.
 */
public class BlockingQueue {

    private Queue<String> buffer = new LinkedList<String>();

    public void put(String data) {
        synchronized (BlockingQueue.class) {
            buffer.add(data);
            notify();
        }
    }

    public String get() throws InterruptedException {
        synchronized (BlockingQueue.class) {
            while (buffer.isEmpty()) {
                wait();
            }
            return buffer.remove();
        }
    }
}
