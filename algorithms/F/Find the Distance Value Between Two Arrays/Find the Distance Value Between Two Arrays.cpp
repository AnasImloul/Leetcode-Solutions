class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        for(int i : arr1){
            int id = lower_bound(arr2.begin(),arr2.end(),i) - arr2.begin();
            int closest = d+1;
            if(id != arr2.size()){
                closest = min(abs(arr2[id]-i), closest);
            } 
            if(id != 0){
                closest = min(abs(arr2[id-1]-i), closest);
            }
            if(closest > d) ans++;
        }
        return ans;
    }
};
