// Runtime: 153 ms (Top 78.43%) | Memory: 55.80 MB (Top 86.27%)

class Solution {
    int[] parent;
    public void union(int i, int j) {
        int parentI = find(i), parentJ = find(j);
        if(parentI < parentJ) {
            parent[parentJ] = parentI;
        } else {
            parent[parentI] = parentJ;
        }
    }
    public int find(int i) {
        int root = i;
        while(parent[root] != root) {
            root = parent[root];
        }
        while(parent[i] != root) {
            int tmp = parent[i];
            parent[i] = root;
            i = tmp;
        }
        return root;
    }
    public boolean canTraverseAllPairs(int[] nums) {
        Map<Integer, List<Integer>> map = new HashMap<>();
        int n = nums.length;
        for(int i=0;i<n;i++) {
            int num = nums[i];
            if(num % 2 == 0) {
                List<Integer> list = map.getOrDefault(2, new ArrayList<>());
                list.add(i);
                map.put(2, list);
                while(num % 2 == 0) {
                    num /= 2;
                }
            }
            for(int p=3;p*p<=num;p+=2) {
                if(num % p == 0) {
                    List<Integer> list = map.getOrDefault(p, new ArrayList<>());
                    list.add(i);
                    map.put(p, list);
                    while(num % p == 0) {
                        num /= p;
                    }
                }
            }
            if(num != 1) {
                List<Integer> list = map.getOrDefault(num, new ArrayList<>());
                list.add(i);
                map.put(num, list);
            }
        }
        parent = new int[n];
        for(int i=0;i<n;i++) {
            parent[i] = i;
        }
        for(int p: map.keySet()) {
            List<Integer> list = map.getOrDefault(p, new ArrayList<>());
            int size = list.size();
            for(int i=0;i<size-1;i++) {
                union(list.get(i), list.get(i+1));
            }
        }
        for(int i=0;i<n;i++) {
            if(find(i) != 0) return false;
        }
        return true;
    }
}
