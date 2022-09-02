// Runtime: 4 ms (Top 74.38%) | Memory: 9.1 MB (Top 32.76%)
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        int diff = arr[1] - arr[0];
        for(int i=1;i<arr.size();i++){
            if(diff != arr[i] - arr[i-1]){
                return false;
            }
        }
        return true;
    }
};