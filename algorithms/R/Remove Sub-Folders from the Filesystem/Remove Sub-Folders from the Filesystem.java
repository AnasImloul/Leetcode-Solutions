class Solution {
    TrieNode root;
    public List<String> removeSubfolders(String[] folder) {
        List<String> res = new ArrayList<>();
        Arrays.sort(folder, (a, b) -> (a.length() - b.length()));
        root = new TrieNode();
        for (String f : folder) {
            if (insert(f)) {
                res.add(f);
            }
        }
        return res;
    }
    
    private boolean insert(String folder) {
        TrieNode node = root;
        char[] chs = folder.toCharArray();
        for (int i = 0; i < chs.length; i++) {
            char ch = chs[i];
            node.children.putIfAbsent(ch, new TrieNode());
            node = node.children.get(ch);
            if (node.isFolder && (i+1 < chs.length && chs[i+1] == '/')) {
                return false;
            }
        }
        node.isFolder = true;
        return true;
    }
}

class TrieNode {
    Map<Character, TrieNode> children = new HashMap<>();
    boolean isFolder;
}
