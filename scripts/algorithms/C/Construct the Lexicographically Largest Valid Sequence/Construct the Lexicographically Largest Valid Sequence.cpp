// Runtime: 0 ms (Top 100.0%) | Memory: 6.80 MB (Top 20.69%)

class Solution {
public:
    
    int SIZE, N;

    bool fillIndex(vector<int> &a, vector<bool> &used, int idx) {
        if(idx == SIZE) return true; 
        if(a[idx]) return fillIndex(a,used,idx+1);
        
        for(int num = N-1 ; num >= 1 ; num--) {
            if(used[num]) continue;
            if(num != 1 and (idx + num >= SIZE or a[idx + num] != 0)) continue;
            a[idx] = num;
            if(num != 1) a[idx+num] = num;
            used[num] = true;
            if(fillIndex(a,used,idx+1)) return true;
            a[idx] = 0 ;
            if(num != 1) a[idx + num] = 0;
            used[num] = false;
        }
        
        return false;
    }
    
    vector<int> constructDistancedSequence(int n) {
        SIZE = 1 + (n-1)*2, N = n;
        vector<int> a(SIZE,0);
        vector<bool> used(n,false);
        
        if(n==1) {
            a[0] = 1;
        } else {
            a[0] = a[n] = n;
            used[n] = true;
            fillIndex(a,used,1);
        }
        
        return a;
    }
};
