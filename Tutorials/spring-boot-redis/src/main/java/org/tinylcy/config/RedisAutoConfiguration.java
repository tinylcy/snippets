package org.tinylcy.config;

import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Import;
import org.tinylcy.utils.CacheUtils;

/**
 * Created by tinylcy.
 */
@Configuration
@Import({RedisConfig.class, CacheUtils.class})
public class RedisAutoConfiguration {
}
