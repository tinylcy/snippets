package org.tinylcy;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by chenyang li.
 */
public class MerkleTreeTest {

    @Test
    public void testMerkleTree() {
        List<String> transactions = new ArrayList<String>();
        transactions.add("a");
//        transactions.add("b");
//        transactions.add("c");
//        transactions.add("d");
//        transactions.add("e");
        MerkleTree merkleTree = new MerkleTree(transactions);
        merkleTree.init();

        System.out.println(merkleTree);
    }
}
