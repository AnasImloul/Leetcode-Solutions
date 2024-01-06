// Runtime: 18 ms (Top 81.73%) | Memory: 25.20 MB (Top 23.35%)

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int c1 = n-2, c2 = n-1;
        while(c1>=0 && arr[c1]<=arr[c1+1])
            c1--;
        if(c1<0)
            return arr;
        while(arr[c2] >= arr[c1] || c2>0 && arr[c2]==arr[c2-1])
            c2--;
        swap(arr[c1], arr[c2]);
        return arr;
    }
};
