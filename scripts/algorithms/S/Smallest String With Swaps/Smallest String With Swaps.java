class Solution {
    int[]parent;
    int[]rank;
    public String smallestStringWithSwaps(String s, List<List<Integer>> pairs) {
        parent = new int[s.length()];
        rank = new int[s.length()];
        for(int i=0;i<parent.length;i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        //Union of All Pairs who belongs to same set
        for(List<Integer> l : pairs){
            int i = l.get(0);
            int j = l.get(1);
            
            int il = find(i);
            int jl = find(j);
            if(il != jl){
                union(il,jl);
            }
        }
        
        //To get the Character in sorted order
        PriorityQueue<Character>[]pq = new PriorityQueue[s.length()];
        for(int i=0;i<pq.length;i++){
            pq[i] = new PriorityQueue<>();
        }
        
        for(int i=0;i<s.length();i++){
            int il = find(i);
            char ch = s.charAt(i);
            pq[il].add(ch);
        }
        
        StringBuilder sb = new StringBuilder();
        for(int i=0;i<s.length();i++){
            int il = find(i);
            char ch = pq[il].remove();
            sb.append(ch);
        }
        
        return sb.toString();
    }
    
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }else{
            parent[x] = find(parent[x]);
            return parent[x];
        }
    }
    void union(int x,int y){
        if(rank[x] < rank[y]){
            parent[x] = y;
        }else if(rank[y] < rank[x]){
            parent[y] = x;
        }else{
            parent[x] = y;
            rank[y]++;
        }
    }
}
