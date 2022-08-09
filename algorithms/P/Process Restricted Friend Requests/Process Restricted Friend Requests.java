class Solution {
    int[] parent;
    boolean[] result;
    
    public boolean[] friendRequests(int n, int[][] restrictions, int[][] requests) {
        parent = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        result = new boolean[requests.length];
        
        for (int i = 0; i < requests.length; i++) {
            // personA and personB can become friends if for all restrictions
            // person x_i and person y_i are not in the same set as personA and personB
            // and vice versa
            int personA = requests[i][0];
            int personB = requests[i][1];
            int personASetRepresentative = find(personA);
            int personBSetRepresentative = find(personB);
            boolean flag = true;
            for (int[] restriction : restrictions) {
                int blackListPersonARepresentative = find(restriction[0]);
                int blackListPersonBRepresentative = find(restriction[1]);
                if (personASetRepresentative == blackListPersonARepresentative && personBSetRepresentative == blackListPersonBRepresentative) {
                    flag = false;
                }
                if (personASetRepresentative == blackListPersonBRepresentative && personBSetRepresentative == blackListPersonARepresentative) {
                    flag = false;
                }
            }
            if (flag) {
                union(personA, personB);
            }
            result[i] = flag;
        }
        return result;
    }
    
    private int find(int node) {
        int root = node;
        while (parent[root] != root) {
            root = parent[root];
        }
        
        //path compression
        int curr = node;
        while (parent[curr] != root) {
            int next = parent[curr];
            parent[curr] = root;
            curr = next;
        }
        return root;
    }
    
    private boolean union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 == root2) {
            return false;
        }
        parent[root2] = root1;
        return true;
    }
}
