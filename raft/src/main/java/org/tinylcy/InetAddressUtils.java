package org.tinylcy;

import java.net.InetAddress;
import java.net.UnknownHostException;

/**
 * Created by tinylcy.
 */
public class InetAddressUtils {

    public static String ip() {
        try {
            InetAddress address = InetAddress.getLocalHost();
            return address.getHostAddress();
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
        return null;
    }
}
