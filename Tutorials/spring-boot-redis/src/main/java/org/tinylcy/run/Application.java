package org.tinylcy.run;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;

import java.io.IOException;
import java.net.ServerSocket;

/**
 * Created by tinylcy.
 */
@SpringBootApplication
@ComponentScan(value = {"org.tinylcy"})
public class Application {

    public static void main(String[] args) throws IOException {
        SpringApplication.run(Application.class, args);

        while (true) {
            int port = 8989;
            ServerSocket server = new ServerSocket(port);
            server.accept();
        }
    }
}
