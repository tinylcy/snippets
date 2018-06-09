package org.tinylcy.ordermessage;

import org.apache.rocketmq.client.consumer.DefaultMQPushConsumer;
import org.apache.rocketmq.client.consumer.listener.ConsumeOrderlyContext;
import org.apache.rocketmq.client.consumer.listener.ConsumeOrderlyStatus;
import org.apache.rocketmq.client.consumer.listener.MessageListenerOrderly;
import org.apache.rocketmq.client.exception.MQClientException;
import org.apache.rocketmq.common.consumer.ConsumeFromWhere;
import org.apache.rocketmq.common.message.MessageExt;

import java.util.List;
import java.util.concurrent.atomic.AtomicLong;

/**
 * Created by tinylcy.
 */
public class Consumer {

    public static void main(String[] args) throws MQClientException {
        final DefaultMQPushConsumer consumer = new DefaultMQPushConsumer("tinylcy_mq_group");
        consumer.setNamesrvAddr("localhost:9876");
        consumer.setConsumeFromWhere(ConsumeFromWhere.CONSUME_FROM_FIRST_OFFSET);
        consumer.subscribe("tinylcy_mq_topic", "TagA || TagB || TagC || TagD || TagE");
        consumer.registerMessageListener(new MessageListenerOrderly() {
            AtomicLong consumeTimes = new AtomicLong(0);

            @Override
            public ConsumeOrderlyStatus consumeMessage(List<MessageExt> msgs, ConsumeOrderlyContext context) {
                context.setAutoCommit(false);
                System.out.printf("%s Receive New Messages: %s%n", Thread.currentThread().getName(), new String(msgs.get(0).getBody()));
                this.consumeTimes.incrementAndGet();
                if (this.consumeTimes.get() % 2 == 0) {
                    return ConsumeOrderlyStatus.SUCCESS;
                } else if (this.consumeTimes.get() % 3 == 0) {
                    return ConsumeOrderlyStatus.ROLLBACK;
                } else if (this.consumeTimes.get() % 4 == 0) {
                    return ConsumeOrderlyStatus.COMMIT;
                } else if (this.consumeTimes.get() % 5 == 0) {
                    context.setSuspendCurrentQueueTimeMillis(3000);
                    return ConsumeOrderlyStatus.SUSPEND_CURRENT_QUEUE_A_MOMENT;
                }
                return ConsumeOrderlyStatus.SUCCESS;
            }
        });

        consumer.start();
        System.out.printf("Consumer Started.%n");
    }
}
