package org.tinylcy;

import com.google.common.hash.Hashing;

import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by chenyang li.
 */
public class MerkleTree {

    /**
     * Transaction list
     */
    private List<String> transactions;

    /**
     * Merkle tree root
     */
    private String root;


    public MerkleTree(List<String> transactions) {
        this.transactions = transactions;
        this.root = "";
    }

    public void init() {
        List<String> merged = null;

        merged = merge(this.transactions);
        while (merged.size() > 1) {
            merged = merge(merged);
        }

        if (merged.size() != 1) {
            throw new RuntimeException("The size of merged transaction list should be equal to 1.");
        }
        this.root = merged.get(0);
    }

    private List<String> merge(List<String> transactions) {
        if (null == transactions || transactions.size() == 0) {
            throw new RuntimeException("The size of transactions should not be empty.");
        }

        Integer size = transactions.size();
        List<String> merged = new ArrayList<String>();
        Integer index = 0;

        if (1 == size) {
            merged.add(sha256hex(transactions.get(0)));
            return merged;
        }

        while (index < size) {
            if (index + 1 == size) {
                merged.add(sha256hex(transactions.get(index)));  // The last transaction.
                break;
            }
            merged.add(sha256hex(transactions.get(index) + transactions.get(index + 1)));
            index += 2;
        }

        return merged;
    }

    private String sha256hex(String text) {
        String result = Hashing.sha256().hashString(text, StandardCharsets.UTF_8).toString();
        return result;
    }

    public List<String> getTransactions() {
        return transactions;
    }

    public void setTransactions(List<String> transactions) {
        this.transactions = transactions;
    }

    public String getRoot() {
        return root;
    }

    public void setRoot(String root) {
        this.root = root;
    }

    @Override
    public String toString() {
        return "MerkleTree{" +
                "transactions=" + transactions +
                ", root='" + root + '\'' +
                '}';
    }
}
