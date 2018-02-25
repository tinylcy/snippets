package org.tinylcy;

import org.junit.Test;

import java.security.PrivateKey;
import java.security.PublicKey;

/**
 * Created by chenyang li.
 */
public class AsymmetricCryptographyTest {

    @Test
    public void testAsymmetricCryptography() throws Exception {
        AsymmetricCryptography ac = new AsymmetricCryptography();
        PrivateKey privateKey = ac.getPrivate("./KeyPair/privateKey");
        PublicKey publicKey = ac.getPublic("./KeyPair/publicKey");

        String msg = "tinylcy";
        String encrypted_msg = ac.encryptText(msg, privateKey);
        String decrypted_msg = ac.decryptText(encrypted_msg, publicKey);
        System.out.println("Original msg is: " + msg);
        System.out.println("Encrypted msg is: " + encrypted_msg);
        System.out.println("Decrypted msg is: " + decrypted_msg);
    }
}
