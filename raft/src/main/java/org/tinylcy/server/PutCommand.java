package org.tinylcy.server;

import io.atomix.copycat.Command;

/**
 * Created by tinylcy.
 */
public class PutCommand implements Command<Object> {
    private final Object key;
    private final Object value;

    public PutCommand(Object key, Object value) {
        this.key = key;
        this.value = value;
    }

    public Object key() {
        return key;
    }

    public Object value() {
        return value;
    }
}
