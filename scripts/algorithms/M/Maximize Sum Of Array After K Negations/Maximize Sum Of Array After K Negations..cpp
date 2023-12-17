// Runtime: 3 ms (Top 82.1%) | Memory: 9.30 MB (Top 79.12%)

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int i, t=0, n=A.size();
        
        for(i=0; i < min(n, K); i++) {
            if(A[t]>=0) break;
            
            else {
                A[t]=-A[t];
                t++;
            }
        }
        
        sort(A.begin(), A.end());
        if(i<K) {
            if((K-i)%2) {
                A[0]=-A[0];
            }
        }
        
        int sum=0;
        for(i=0; i<A.size(); i++) {
            sum += A[i];
        }
        return sum;
    }
};
