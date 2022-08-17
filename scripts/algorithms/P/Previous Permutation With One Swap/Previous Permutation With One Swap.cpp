class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i, p, mn = -1;
        for(i=arr.size() - 2; i>=0; i--) {
            if(arr[i] > arr[i + 1]) break;
        }
        if(i == -1) return arr;

        for(int j=i + 1; j<arr.size(); j++) {
            if(arr[j] > mn && arr[j] < arr[i]) mn = arr[j], p = j;
    
        }
        swap(arr[i], arr[p]);
        return arr;
    }
};
