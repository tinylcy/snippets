package org.tinylcy;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;
import org.tinylcy.run.Application;
import org.tinylcy.utils.CacheUtils;

import static org.junit.Assert.*;

/**
 * Created by tinylcy.
 */
@RunWith(SpringRunner.class)
@SpringBootTest(classes = Application.class)
public class BaseTest {

    @Test
    public void test() {
        CacheUtils.hashSet("test", "tinylcy", "tinylcy.me");
        assertEquals(CacheUtils.hashGet("test", "tinylcy"), "tinylcy.me");
    }
}
