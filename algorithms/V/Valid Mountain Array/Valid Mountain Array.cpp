class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int flag = 1;
        if((arr.size()<=2) || (arr[1] <= arr[0])) return false;
        for(int i=1; i<arr.size(); i++){
            if(flag){
                if(arr[i] > arr[i-1]) continue;
                i--;
                flag = 0;
            }
            else{
                if(arr[i] < arr[i-1]) continue;
                return false;
            }
        }

        if(flag) return false;
        return true;
        
    }
};****
