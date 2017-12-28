package org.tinylcy;

import org.apache.commons.codec.binary.Base64;

import javax.crypto.Cipher;
import javax.crypto.NoSuchPaddingException;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.nio.file.Files;
import java.security.*;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;

/**
 * Created by chenyang li.
 */
public class AsymmetricCryptography {

    private Cipher cipher;

    public AsymmetricCryptography() throws NoSuchAlgorithmException, NoSuchPaddingException {
        this.cipher = Cipher.getInstance("RSA");
    }

    public PrivateKey getPrivate(String path) throws IOException, NoSuchAlgorithmException,
            InvalidKeySpecException {
        byte[] keyBytes = Files.readAllBytes(new File(path).toPath());
        PKCS8EncodedKeySpec spec = new PKCS8EncodedKeySpec(keyBytes);
        KeyFactory kf = KeyFactory.getInstance("RSA");
        return kf.generatePrivate(spec);
    }

    public PublicKey getPublic(String path) throws IOException, NoSuchAlgorithmException,
            InvalidKeySpecException {
        byte[] keyBytes = Files.readAllBytes(new File(path).toPath());
        X509EncodedKeySpec spec = new X509EncodedKeySpec(keyBytes);
        KeyFactory kf = KeyFactory.getInstance("RSA");
        return kf.generatePublic(spec);
    }

    public void encrptyFile(byte[] input, File output, PrivateKey key) throws
            GeneralSecurityException, IOException {
        this.cipher.init(Cipher.ENCRYPT_MODE, key);
        writeToFile(output, this.cipher.doFinal(input));
    }

    public void decryptFile(byte[] input, File output, PublicKey key) throws
            GeneralSecurityException, IOException {
        this.cipher.init(Cipher.DECRYPT_MODE, key);
        writeToFile(output, this.cipher.doFinal(input));
    }

    public String encryptText(String msg, PrivateKey key) throws GeneralSecurityException,
            UnsupportedEncodingException {
        this.cipher.init(Cipher.ENCRYPT_MODE, key);
        return Base64.encodeBase64String(this.cipher.doFinal(msg.getBytes("UTF-8")));
    }

    public String decryptText(String msg, PublicKey key) throws GeneralSecurityException,
            UnsupportedEncodingException {
        this.cipher.init(Cipher.DECRYPT_MODE, key);
        return new String(cipher.doFinal(Base64.decodeBase64(msg)), "UTF-8");
    }

    private void writeToFile(File output, byte[] toWrite) throws IOException {
        FileOutputStream out = new FileOutputStream(output);
        out.write(toWrite);
        out.flush();
        out.close();
    }
}
