package org.tinylcy.utils;

import org.springframework.data.redis.core.RedisTemplate;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;

/**
 * Created by tinylcy.
 */
public class CacheUtils {

    @Resource
    private RedisTemplate<String, String> redisTemplate;
    private static CacheUtils cacheUtils;

    @PostConstruct
    public void init() {
        cacheUtils = this;
        cacheUtils.redisTemplate = this.redisTemplate;
    }

    /**
     * 保存到 hash 集合中
     *
     * @param hName
     * @param key
     * @param value
     */
    public static void hashSet(String hName, String key, String value) {
        cacheUtils.redisTemplate.opsForHash().put(hName, key, value);
    }

    /**
     * 从 hash 集合中取值
     *
     * @param hName
     * @param key
     * @return
     */
    public static Object hashGet(String hName, String key) {
        return cacheUtils.redisTemplate.opsForHash().get(hName, key);
    }
}
