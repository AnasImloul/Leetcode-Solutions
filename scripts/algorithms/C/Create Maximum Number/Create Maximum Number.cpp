class Solution {
public:
    vector<int> maxArray(vector<int>&nums,int k){
        int n=nums.size();
        stack<int>seen;
        for(int i=0;i<n;i++){
            int right=n-i-1;
            while(not seen.empty() and seen.top()<nums[i] and right+seen.size()>=k)seen.pop();
            if(seen.size()<k)seen.push(nums[i]);
        }
        vector<int>res(k,0);
        for(int i=res.size()-1;i>=0;i--){
            res[i]=seen.top();
            seen.pop();
        }
        return res;
    }
    bool greater(vector<int>&arr1,int i,vector<int>&arr2,int j){
        for(;i<arr1.size() and j<arr2.size();i++,j++){
            if(arr1[i]==arr2[j])continue;
            return arr1[i]>arr2[j];
        }
        return i!=arr1.size();
    }
    vector<int> merge(vector<int>&arr1,vector<int>&arr2){
        vector<int>res(arr1.size()+arr2.size());
        for(int ind=0,i=0,j=0;ind<res.size();ind++){
            if(greater(arr1,i,arr2,j)){
                res[ind]=arr1[i];
                i++;
            }else{
                res[ind]=arr2[j];
                j++;
            }
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m=nums1.size(),n=nums2.size();
        vector<int>ans;
        for(int len1=max(0,k-n);len1<=min(m,k);len1++){
            int len2 = k-len1;
            vector<int> arr1 = maxArray(nums1,len1);
            vector<int> arr2 = maxArray(nums2,len2);
            vector<int> temp_res = merge(arr1,arr2);
            if(greater(temp_res,0,ans,0)){
                ans.resize(temp_res.size());
                for(int i=0;i<temp_res.size();i++){
                    ans[i]=temp_res[i];
                }
            }
        }
        return ans;
    }
};