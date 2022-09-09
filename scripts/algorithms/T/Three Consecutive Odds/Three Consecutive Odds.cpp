// Runtime: 8 ms (Top 31.62%) | Memory: 8.2 MB (Top 80.71%)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int k = 0;
        for(int i=0;i<arr.size();i++){
            if(arr[i] % 2 != 0){
                k++;
                if(k == 3){
                    return true;
                }
            }else{
                k = 0;
            }
        }
        return false;
    }
};