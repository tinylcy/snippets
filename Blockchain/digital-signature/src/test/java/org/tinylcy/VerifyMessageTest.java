package org.tinylcy;

import org.junit.Test;

/**
 * Created by chenyang li.
 */
public class VerifyMessageTest {

    @Test
    public void testVerifyMessage() throws Exception{
        new VerifyMessage("./MyData/SignedData.txt", "./KeyPair/publicKey");
    }
}
