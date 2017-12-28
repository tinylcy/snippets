package org.tinylcy;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.security.*;
import java.security.spec.InvalidKeySpecException;
import java.security.spec.PKCS8EncodedKeySpec;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by chenyang li.
 */
public class Message {

    private List<byte[]> list;

    public Message(String data, String keyFile) throws GeneralSecurityException, IOException {
        this.list = new ArrayList<byte[]>();
        list.add(data.getBytes());
        list.add(sign(data, keyFile));
    }

    public byte[] sign(String data, String keyPair) throws IOException, GeneralSecurityException {
        Signature rsa = Signature.getInstance("SHA1withRSA");
        rsa.initSign(getPrivate(keyPair));
        rsa.update(data.getBytes());
        return rsa.sign();
    }

    public void writeToFile(String path) throws IOException {
        File file = new File(path);
        file.getParentFile().mkdirs();
        ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream(file));
        out.writeObject(this.list);
        out.close();
        System.out.println("Your file is ready.");
    }

    private PrivateKey getPrivate(String path) throws IOException,
            NoSuchAlgorithmException, InvalidKeySpecException {
        byte[] keyBytes = Files.readAllBytes(new File(path).toPath());
        PKCS8EncodedKeySpec spec = new PKCS8EncodedKeySpec(keyBytes);
        KeyFactory kf = KeyFactory.getInstance("RSA");
        return kf.generatePrivate(spec);
    }

}
