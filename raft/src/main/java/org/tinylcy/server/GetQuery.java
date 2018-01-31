package org.tinylcy.server;

import io.atomix.copycat.Query;

/**
 * Created by tinylcy.
 */
public class GetQuery implements Query<Object> {

    private final Object key;

    public GetQuery(Object key) {
        this.key = key;
    }

    public Object key() {
        return key;
    }
}
