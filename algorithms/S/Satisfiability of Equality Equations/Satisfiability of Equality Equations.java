class Solution {
    private class UF{
        int count;
        int[] parent;
        
        public UF(int n){
            count = n;
            parent = new int[n];
            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }
        
        public int find(int x){
            if(parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        public void union(int a, int b){
            int rootA = find(a);
            int rootB = find(b);
            if(rootA == rootB){
                return;
            }
            parent[rootA] = rootB;
            count --;
        }
        
        public boolean connected(int a, int b){
            int rootA = find(a);
            int rootB = find(b);
            if(rootA == rootB){
                return true;
            }else{
                return false;
            }
        }
    }
    public boolean equationsPossible(String[] equations) {
        UF uf = new UF(26);
        int count = 0;
        for(String s : equations){
            if(s.charAt(1) == '='){
                uf.union(s.charAt(0) - 'a', s.charAt(3) - 'a');
            }else{
                equations[count] = s;
                count++;
            }
        }
        for(String s : equations){
            count --;
            if(count < 0){
                break;
            }
            if(s.charAt(1) == '!'){
                if(uf.connected(s.charAt(0) - 'a', s.charAt(3) - 'a')){
                    return false;
                }
            }
        }
        return true;
    }
}
