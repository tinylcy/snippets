package org.tinylcy;

import org.junit.Test;

import java.io.IOException;
import java.security.NoSuchAlgorithmException;

/**
 * Created by chenyang li.
 */
public class GenerateKeysTest {

    @Test
    public void testGenerateKeys() {
        GenerateKeys gk;

        try {
            gk = new GenerateKeys(1024);
            gk.createKeys();
            gk.writeToFile("./KeyPair/privateKey", gk.getPrivateKey().getEncoded());
            gk.writeToFile("./KeyPair/publicKey", gk.getPublicKey().getEncoded());
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}