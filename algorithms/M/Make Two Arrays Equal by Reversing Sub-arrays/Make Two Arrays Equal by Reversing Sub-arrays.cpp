class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int arr1[1001]={0};
        int arr2[1001]={0};
        
        for(int i =0 ; i<target.size(); i++)
        {
            arr1[arr[i]]++;
            arr2[target[i]]++;
        }
        
        for(int i =0 ;i<=1000;i++)
        {
            if(arr1[i]!=arr2[i])
                return false;
        }
        return true;
    }
};
