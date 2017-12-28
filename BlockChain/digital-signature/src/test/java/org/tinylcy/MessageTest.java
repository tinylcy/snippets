package org.tinylcy;

import org.junit.Test;

import javax.swing.*;
import java.io.IOException;
import java.security.GeneralSecurityException;

/**
 * Created by chenyang li.
 */
public class MessageTest {

    @Test
    public void testMessage() throws GeneralSecurityException, IOException {
        String data = JOptionPane.showInputDialog("Type your message here.");
        new Message(data, "./KeyPair/privateKey").writeToFile("./MyData/SignedData.txt");
    }
}
