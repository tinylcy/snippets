package org.tinylcy;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.nio.file.Files;
import java.security.GeneralSecurityException;
import java.security.KeyFactory;
import java.security.PublicKey;
import java.security.Signature;
import java.security.spec.X509EncodedKeySpec;
import java.util.List;

/**
 * Created by chenyang li.
 */
public class VerifyMessage {

    private List<byte[]> list;

    public VerifyMessage(String path, String keyFile)
            throws IOException, ClassNotFoundException, GeneralSecurityException {
        ObjectInputStream in = new ObjectInputStream(new FileInputStream(new File(path)));
        this.list = (List<byte[]>) in.readObject();
        in.close();
        System.out.println(verifySignature(list.get(0), list.get(1), keyFile) ? "VERIFIED MESSAGE"
                + "\n--------------------\n"
                + new String(list.get(0)) : "Could not verify a signature.");
    }

    private Boolean verifySignature(byte[] data, byte[] signature, String keyFile)
            throws GeneralSecurityException, IOException {
        Signature rsa = Signature.getInstance("SHA1withRSA");
        rsa.initVerify(getPublic(keyFile));
        rsa.update(data);
        return rsa.verify(signature);
    }

    private PublicKey getPublic(String path) throws IOException, GeneralSecurityException {
        byte[] keyBytes = Files.readAllBytes(new File(path).toPath());
        X509EncodedKeySpec spec = new X509EncodedKeySpec(keyBytes);
        KeyFactory kf = KeyFactory.getInstance("RSA");
        return kf.generatePublic(spec);
    }
}
