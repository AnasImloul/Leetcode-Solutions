// Runtime: 13 ms (Top 59.15%) | Memory: 91.1 MB (Top 32.39%)
//Solving the problem using Disjoint Set Union Find approach

class Solution {

    public int find(int x){

        if(parent[x] == x)
            return x;

        //Optimising by placing the same parent for all the elements to reduce reduntant calls
        return parent[x] = find(parent[x]);
    }

    public void union(int a, int b){

        a = find(a);
        b = find(b);

        //Using Rank optimisation
        if(rank[a] > rank[b]){
            parent[b] = a;
            rank[a] += rank[b];
        }

        else{
            parent[a] = b;
            rank[b] += rank[a];
        }

        //parent[b] = a;
    }

    int parent[];
    int rank[];
    public List<Boolean> areConnected(int n, int threshold, int[][] queries) {

        List<Boolean> ans = new ArrayList<Boolean>();
        parent = new int[n+1];
        rank = new int[n+1];

        for(int i=1; i<=n; i++){
            //Each element is its own parent
            parent[i] = i;
            //At beginning each element has rank 1
            rank[i] = 1;
        }

        // Finding the possible divisors with pairs above given threshold
        for(int th = threshold+1; th<=n; th++){

            int mul = 1;
            while(mul * th <= n){
                //If possible pair then making a union of those paired element
                union(th, mul*th);
                mul++;
            }
        }

        //Generating ans for all possible queries
        for(int[] query : queries){
            ans.add((find(query[0]) == find(query[1])));
        }
        return ans;
    }
}