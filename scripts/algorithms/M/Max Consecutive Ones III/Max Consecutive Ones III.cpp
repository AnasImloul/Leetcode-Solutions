// Runtime: 72 ms (Top 5.04%) | Memory: 55.80 MB (Top 77.26%)

class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
       int start = 0, max = INT_MIN,zeroCounter=0;
        for(int end=0 ; end<A.size() ; end++){
            if(A[end]==0){
                zeroCounter++;
            }
            while(zeroCounter>K){
                if(A[start]==0){
                    zeroCounter--;
                }
                start++;
            }
            
            max = std::max(max,end-start+1);
        }
        
        return max;
    }
};
