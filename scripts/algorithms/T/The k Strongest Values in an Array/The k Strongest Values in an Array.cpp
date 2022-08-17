class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        if(arr.size()<=k){
            return arr;
        } else {
            sort(arr.begin(),arr.end());
            vector<int>ans;
            int start=0,end=arr.size()-1;
            int median=arr[(arr.size()-1)/2];
            while(k!=0 and start<end){
                if(abs(arr[start]-median)==abs(arr[end]-median)){
                    if(arr[start]>arr[end]){
                     ans.push_back(arr[start++]);
                    } else {
                        ans.push_back(arr[end--]);
                    }
                } else if(abs(arr[start]-median)>abs(arr[end]-median)){
                    ans.push_back(arr[start++]);
                } else {
                    ans.push_back(arr[end--]);
                }
                k--;
            }
            return ans;
        }
    }
};