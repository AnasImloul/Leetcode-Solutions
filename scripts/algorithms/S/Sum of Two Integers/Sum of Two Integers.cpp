class Solution {
public:
    int getSum(int a, int b) {
        vector<int> arr = {a,b};
        return accumulate(arr.begin(),arr.end(),0);
    }
};
