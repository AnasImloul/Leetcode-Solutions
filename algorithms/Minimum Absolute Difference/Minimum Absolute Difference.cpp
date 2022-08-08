class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int diff=INT_MAX;
        for(int i=1;i<arr.size();i++){
            diff=min(diff,abs(arr[i]-arr[i-1]));
        }
        vector<vector<int>>v;
        for(int i=1;i<arr.size();i++){
            if(abs(arr[i]-arr[i-1])==diff){
                int a=min(arr[i],arr[i-1]);
                int b=max(arr[i],arr[i-1]);
                v.push_back({a,b});
            }  
        }
        return v;
    }
};
