// Runtime: 113 ms (Top 56.94%) | Memory: 96.10 MB (Top 55.89%)

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long sum = 0, fn = 0;
        int len = A.size();
        for(int i=0;i<len;i++) {
            sum += A[i];
            fn += (i * A[i]);
        }

        long l = 1, r;
        long newfn = fn;
        
        while(l < len) {
            r = l + len - 1;
            
            long removed = (l-1) * A[l-1];
            long added = r * A[r%len];
            
            newfn = newfn - removed + added - sum;
            
            fn = max(fn, newfn);
            
            l++;
        }
        
        return (int)fn;
    }
};
