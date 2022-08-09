class Solution {
    
    public List<List<String>> deleteDuplicateFolder(List<List<String>> paths) {
        Trie node = new Trie("/");
        for (List<String> val : paths) {
            insert(node, val);
        }
        HashMap<String, Boolean> map = new HashMap<>();
        dfsTrie(node, map);
        removeNode(node, map);
        List<List<String>> ans = new ArrayList<>();
        getAnswer(node, new LinkedList<>(), ans);
        return ans;

    }

    void insert(Trie node, List<String> paths) {
        for (String a : paths) {
            if (node.next.get(a) == null) {
                node.next.put(a, new Trie(a));
            }
            node = node.next.get(a);
        }
    }

    String dfsTrie(Trie node, HashMap<String, Boolean> map) {
        StringBuilder sb = new StringBuilder();
        for (Trie val : node.next.values()) {
            if (val != null) {
                String rec = dfsTrie(val, map);
                if (rec.length()>0 && map.containsKey(rec)) {
                    map.put(rec, true);
                } else {
                    map.put(rec, false);
                }
                sb.append(rec + val.a);
            }
        }
        node.dirName = sb.toString();
        return sb.toString();
    }

    void removeNode(Trie node, HashMap<String, Boolean> map) {
        for (Map.Entry<String,Trie> val : node.next.entrySet() ) {
            if (val.getValue().dirName != null && map.get(val.getValue().dirName)) {
                node.next.put(val.getKey(), null);
            }
            if (node.next.get(val.getKey()) != null) {
                removeNode(node.next.get(val.getKey()), map);
            }
        }
    }

    void getAnswer(Trie node, LinkedList<String> res, List<List<String>> ans) {
        for (Trie val : node.next.values()) {
            if (val != null) {
                res.add(val.a + "");
                ans.add(new ArrayList<>(res));
                getAnswer(val, res, ans);
                res.removeLast();
            }
        }
    }

    class Trie {
        String a;
        HashMap<String, Trie> next;
        String dirName;

        Trie(String a) {
            this.a = a;
            this.next = new HashMap<>();
            dirName = null;
        }
    }

}
