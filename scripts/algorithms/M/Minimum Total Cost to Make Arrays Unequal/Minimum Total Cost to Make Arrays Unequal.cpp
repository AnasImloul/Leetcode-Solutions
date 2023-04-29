class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        int domNum = -1,domCount = 0,totalNum = 0,n = nums1.size();
        long ans = 0;
        unordered_map<int,int> store;   //store freq of duplicates in nums1 ad nums2

        for(int i=0;i<n;i++){
            if(nums1[i] == nums2[i]){
                ans = ans + i;
                store[nums1[i]]++;

                if(store[nums1[i]] > domCount){
                    domCount = store[nums1[i]];
                    domNum = nums1[i];
                }

                totalNum++;
            }
        }

        if( domCount <= (totalNum/2)){
            //Means Each duplicates will swap among themselves to get the required array
            return ans;
        }
        else{
            //Duplicates have to be swapped with other elements of original Array

            for(int i=0;i<n;i++){
                if(nums1[i] != nums2[i] && nums1[i] != domNum && nums2[i] != domNum){
                    ans = ans + i;
                    totalNum++;

                }
                
                if( domCount <= (totalNum/2)){
                    //Got the required Array , Can stop now
                    return ans;
                }

            }
        }

        //Not Possible
        return -1;
        
    }


};