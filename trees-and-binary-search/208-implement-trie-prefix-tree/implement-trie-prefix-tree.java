class Trie {

    class TrieNode {
        TrieNode[] child = new TrieNode[26];
        boolean end;
    }

    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void insert(String word) {

        TrieNode curr = root;

        for (char ch : word.toCharArray()) {

            int idx = ch - 'a';

            if (curr.child[idx] == null) {
                curr.child[idx] = new TrieNode();
            }

            curr = curr.child[idx];
        }

        curr.end = true;
    }

    public boolean search(String word) {

        TrieNode curr = root;

        for (char ch : word.toCharArray()) {

            int idx = ch - 'a';

            if (curr.child[idx] == null) {
                return false;
            }

            curr = curr.child[idx];
        }

        return curr.end;
    }

    public boolean startsWith(String prefix) {

        TrieNode curr = root;

        for (char ch : prefix.toCharArray()) {

            int idx = ch - 'a';

            if (curr.child[idx] == null) {
                return false;
            }

            curr = curr.child[idx];
        }

        return true;
    }
}