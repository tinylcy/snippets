package org.tinylcy.client;

import io.atomix.catalyst.transport.Address;
import io.atomix.catalyst.transport.netty.NettyTransport;
import io.atomix.copycat.client.CopycatClient;
import org.tinylcy.server.GetQuery;
import org.tinylcy.server.PutCommand;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CompletableFuture;

/**
 * Created by tinylcy.
 */
public class Client {

    public static void main(String[] args) {

        /* Build a list of all member addresses to which to connect. */
        List<Address> members = new ArrayList<>();
        members.add(new Address("192.168.0.121", 5000));
        members.add(new Address("192.168.0.124", 5000));

        CopycatClient.Builder builder = CopycatClient.builder(members);
        builder.withTransport(NettyTransport.builder()
                .withThreads(2)
                .build());

        CopycatClient client = builder.build();

        client.serializer().register(PutCommand.class);
        client.serializer().register(GetQuery.class);

        client.connect(members).join();

        CompletableFuture[] futures = new CompletableFuture[3];
        futures[0] = client.submit(new PutCommand("foo", "Hello World"));
        futures[1] = client.submit(new PutCommand("bar", "Hello World"));
        futures[2] = client.submit(new PutCommand("baz", "Hello World"));

        CompletableFuture.allOf(futures).thenRun(() -> System.out.println("Commands completed!"));

        client.submit(new GetQuery("foo")).thenAccept(result -> {
            System.out.println("foo is: " + result);
        });

    }
}
