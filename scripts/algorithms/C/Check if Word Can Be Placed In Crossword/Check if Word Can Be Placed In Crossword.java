// Runtime: 522 ms (Top 5.97%) | Memory: 200.3 MB (Top 5.41%)
class Solution {
    public boolean placeWordInCrossword(char[][] board, String word) {
        String curr = "";

        Trie trie = new Trie();

        // Insert all horizontal strings
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == '#') {
                    insertIntoTrie(trie, curr);
                    curr = "";
                }
                else {
                    curr += board[i][j];
                }
            }
            insertIntoTrie(trie, curr);
            curr = "";
        }

        // Insert all vertical strings
        for (int i = 0; i < board[0].length; i++) {
            for (int j = 0; j < board.length; j++) {
                if (board[j][i] == '#') {
                    insertIntoTrie(trie, curr);
                    curr = "";
                }
                else {
                    curr += board[j][i];
                }
            }
            insertIntoTrie(trie, curr);
            curr = "";
        }

        return trie.isPresent(word);
    }

    // Insert string and reverse of string into the trie
    private void insertIntoTrie(Trie trie, String s) {
        trie.insert(s);
        StringBuilder sb = new StringBuilder(s);
        sb.reverse();
        trie.insert(sb.toString());
    }

    class TrieNode {
        Map<Character, TrieNode> children;
        boolean isEnd;

        TrieNode() {
            children = new HashMap<>();
            isEnd = false;
        }

    }

    class Trie {
        TrieNode root;

        Trie() {
            root = new TrieNode();
        }

        void insert(String s) {
            TrieNode curr = root;

            for (int i = 0; i < s.length(); i++)
            {
                char c = s.charAt(i);
                if (!curr.children.containsKey(c)) {
                    curr.children.put(c, new TrieNode());
                }

                curr = curr.children.get(c);
            }

            curr.isEnd = true;
        }

        boolean isPresent(String key) {
            TrieNode curr = root;
            return helper(key, 0, root);

        }

        boolean helper(String key, int i, TrieNode curr) {
            if (curr == null)
                return false;

            if (i == key.length())
                return curr.isEnd;

            char c = key.charAt(i);
            return helper(key, i + 1, curr.children.get(c)) || helper(key, i + 1, curr.children.get(' '));

        }
    }
}