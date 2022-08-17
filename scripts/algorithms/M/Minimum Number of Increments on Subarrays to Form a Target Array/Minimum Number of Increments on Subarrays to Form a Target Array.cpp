class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int res = target[0];
        int prev = target[0];
        
        for (int i=1; i<target.size(); i++ ){
            if (target[i]>prev){
                res += (target[i]-prev);
            }
            prev=target[i];
        }
        return res;
    }
};
