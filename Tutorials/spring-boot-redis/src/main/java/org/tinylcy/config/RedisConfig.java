package org.tinylcy.config;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.data.redis.connection.jedis.JedisConnectionFactory;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.data.redis.serializer.StringRedisSerializer;

/**
 * 配置 RedisTemplate 实例
 * <p>
 * Created by tinylcy.
 */
@Configuration
public class RedisConfig {

    private Logger LOG = LoggerFactory.getLogger(RedisConfig.class);

    @Bean
    public JedisConnectionFactory jedisConnectionFactory() {
        return new JedisConnectionFactory();
    }

    public RedisTemplate<String, String> redisTemplate() {
        RedisTemplate<String, String> template = new RedisTemplate<>();
        template.setConnectionFactory(jedisConnectionFactory());
        template.setKeySerializer(new StringRedisSerializer());
        LOG.info("create RedisTemplate success.");
        return template;
    }
}
