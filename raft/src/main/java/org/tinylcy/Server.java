package org.tinylcy;

import io.atomix.catalyst.transport.Address;
import io.atomix.catalyst.transport.netty.NettyTransport;
import io.atomix.copycat.server.CopycatServer;
import io.atomix.copycat.server.storage.Storage;
import io.atomix.copycat.server.storage.StorageLevel;

import java.io.File;
import java.util.concurrent.CompletableFuture;

/**
 * Created by tinylcy.
 */
public class Server {

    public static void main(String[] args) {
        Address address = new Address(InetAddressUtils.ip(), 5000);
        CopycatServer.Builder builder = CopycatServer.builder(address);

        builder.withStateMachine(MapStateMachine::new);

        builder.withTransport(NettyTransport.builder()
                .withThreads(4)
                .build());

        builder.withStorage(Storage.builder()
                .withDirectory(new File("logs"))
                .withStorageLevel(StorageLevel.DISK)
                .build());

        CopycatServer server = builder.build();
        server.serializer().register(PutCommand.class);
        server.serializer().register(GetQuery.class);

        CompletableFuture<CopycatServer> future = server.bootstrap();

        future.join();
    }
}
