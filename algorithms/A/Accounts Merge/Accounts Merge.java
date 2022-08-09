class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        
        int l = accounts.size();
        UnionFind uf = new UnionFind(l);
        
        Map<String, Integer> emailToNameId = new HashMap<>();
        
        for(int i=0; i<l; i++) {
            List<String> account = accounts.get(i);
            for(int j=1; j<account.size(); j++) {
                String email = account.get(j);
                int currentNameId = i;
                if (emailToNameId.containsKey(email)) {
                    int oldNameId = emailToNameId.get(email);
                    // Join new and old name ids so that we can know which emails can be merged together. Emails in a single component can be merged together.
                    uf.union(currentNameId, oldNameId);
                } else {
                    emailToNameId.put(email, currentNameId);
                }
            }
        }
        // emailToNameId = {johnnybravo@mail.com=3, johnsmith@mail.com=0, john00@mail.com=1, john_newyork@mail.com=0, mary@mail.com=2}

        // Use TreeSet for alphabetical order. 
        Map<Integer, TreeSet<String>> nameIdToEmails = new HashMap<>();
        for(int i=0; i<l; i++) {
            int root = uf.find(i);
            nameIdToEmails.putIfAbsent(root, new TreeSet<>());
            List<String> account = accounts.get(i);
            List<String> emails = account.subList(1, account.size());
            nameIdToEmails.get(root).addAll(emails);
        }
        // nameIdToEmails = {1=[john00@mail.com, john_newyork@mail.com, johnsmith@mail.com], 2=[mary@mail.com], 3=[johnnybravo@mail.com]}

        List<List<String>> out = new ArrayList<>();
        for(int id : nameIdToEmails.keySet()) {
            String name = accounts.get(id).get(0);
            List<String> emails = new ArrayList<>(nameIdToEmails.get(id));
            emails.add(0, name);
            out.add(emails);
        }
        return out;
    }
    
    class UnionFind {
        int[] parent;
        int[] rank;
        
        UnionFind(int size) {
            parent = new int[size];
            rank = new int[size];
            for(int i=0; i<size; i++) {
                parent[i] = i;
                rank[i] = 1;
            }
        }
        
        public void union(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX] += 1;
                }
            }
        }
        
        public int find(int x) {
            if (x == parent[x]) {
                return x;
            }
            return parent[x] = find(parent[x]);
        }
        
        
    }
}
