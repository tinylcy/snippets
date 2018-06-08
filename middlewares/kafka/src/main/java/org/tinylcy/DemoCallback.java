package org.tinylcy;

import org.apache.kafka.clients.producer.Callback;
import org.apache.kafka.clients.producer.RecordMetadata;

/**
 * Created by tinylcy.
 */
public class DemoCallback implements Callback {

    private final long startTime;
    private final int key;
    private final String message;

    public DemoCallback(long startTime, int key, String message) {
        this.startTime = startTime;
        this.key = key;
        this.message = message;
    }

    /**
     * A callback method the user can implement to provide asynchronous handling of request completion.
     * This method will be called when the record sent to the server has been acknowledged. Exactly on
     * of the argument will be non-null.
     *
     * @param metadata The metadata for the record that was sent. Null if an error occurred.
     * @param e
     */
    @Override
    public void onCompletion(RecordMetadata metadata, Exception e) {
        long elapsedTime = System.currentTimeMillis() - startTime;
        if (metadata != null) {
            System.out.println("Message(" + key + ", " + message +
                    ") sent to partition(" + metadata.partition() +
                    "), " + "offset(" + metadata.offset() + ") in " + elapsedTime + "ms");
        } else {
            e.printStackTrace();
        }
    }
}
