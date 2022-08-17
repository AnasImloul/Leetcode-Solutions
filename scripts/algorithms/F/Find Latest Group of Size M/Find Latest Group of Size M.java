
class Solution {
    int[] par, size, count, bits;    
    // par: parent array, tells about whose it the parent of ith element
    // size: it tells the size of component
    // count: it tells the count of islands (1111 etc) of size i;
    // count[3] = 4: ie -> there are 4 islands of size 3
    
    public int find(int u) {
        if (u == par[u]) return u;
        par[u] = find(par[u]);
        return par[u];
    }
    
    public void union(int u, int v) {
        // union is performed over parents of elements not nodes itself
        int p1 = find(u), p2 = find(v);
        if (p1 == p2) return;
        
        // decrease the count of islands of size p1, p2
        count[size[p1]]--;
        count[size[p2]]--;
        
        // now merge
        par[p2] = p1;
        
        // adjust sizes
        size[p1] += size[p2];
        
        // adjust the count of islands of new size ie: size of p1
        count[size[p1]]++;
    }
    
    public int findLatestStep(int[] arr, int m) {
        int n = arr.length;
        par = new int[n + 1];
        size = new int[n + 1];
        count = new int[n + 1];
        bits = new int[n + 2];
        
        for (int i = 0; i < n; i++) {
            par[i] = i;
            size[i] = 1;
        }
        
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int idx = arr[i];
            // set the bit
            bits[idx] = 1;
            // increase the count of islands of size 1
            count[1]++;
            
            if (bits[idx - 1] > 0) {
                union(idx, idx - 1);
            }   
            if (bits[idx + 1] > 0) {
                union(idx, idx + 1);
            }
            
            // check if island of size m exists
            if (count[m] > 0) {
                ans = i + 1;
                // as it is 1 based indexing
            }
        }
        return ans;
    }
}

