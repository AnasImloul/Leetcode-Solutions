class Solution {
    public int minimumHammingDistance(int[] source, int[] target, int[][] allowedSwaps) {
        int minHamming = 0;
        UnionFind uf = new UnionFind(source.length);
        for (int [] swap : allowedSwaps) {
            int firstIndex = swap[0];
            int secondIndex = swap[1];
           // int firstParent = uf.find(firstIndex);
           // int secondParent = uf.find(secondIndex);
           // if (firstParent != secondParent)
           //     uf.parent[firstParent] = secondParent;
		   uf.union(firstIndex, secondIndex);
        }
        Map<Integer, Map<Integer, Integer>> map = new HashMap<>();
        for (int i=0; i<source.length; i++) {
            int num = source[i];
            int root = uf.find(i);
            map.putIfAbsent(root, new HashMap<>());
            Map<Integer, Integer> store = map.get(root);
            store.put(num, store.getOrDefault(num, 0) + 1);
        }
        for (int i=0; i<source.length; i++) {
            int num = target[i];
            int root = uf.find(i);
            Map<Integer, Integer> store = map.get(root);
            if (store.getOrDefault(num, 0) == 0)
                minHamming += 1;
            else
                store.put(num, store.get(num) - 1);
        }
        return minHamming;
    }
}

class UnionFind {
    int size;
    int components;
    int [] parent;
    int [] rank;
    UnionFind(int n) {
        if (n <= 0) throw new IllegalArgumentException("Size <= 0 is not allowed");
        size = n;
        components = n;
        parent = new int [n];
        rank = new int [n];
        for (int i=0; i<n; i++)
            parent[i] = i;
    }
    
    public int find(int p) {
        while (p != parent[p]) {
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }
    
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rank[rootQ] > rank[rootP]) {
            parent[rootP] = rootQ;
        }
        else {
            parent[rootQ] = rootP;
            if (rank[rootQ] == rank[rootP])
                rank[rootP] += 1;
        }
        components -= 1;
    }
    
    public int size() {
        return size;
    }
    
    public boolean isConnected(int p, int q) {
        return find(p) == find(q);
    }
    
    public int numberComponents() {
        return components;
    }
}
