// Runtime: 937 ms (Top 48.06%) | Memory: 237.5 MB (Top 19.94%)
class Solution {
public:

    int merge_count(vector<int> &nums,int s,int e){
        int i;
        int mid = (s+e)/2;
        int j=mid+1;
        long long int count=0;
        for(i=s;i<=mid;i++){
            while((j<=e)&&((double)nums[i]/2.0)>nums[j]){
                j++;
            }
            count += j-(mid+1);
        }
        i=s;j=mid+1;
        vector<int> ans;
        while((i<=mid)&&(j<=e)){
            if(nums[i]<=nums[j]){
                ans.push_back(nums[i]);
                i++;
            }
            else{
                ans.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            ans.push_back(nums[i]);
            i++;
        }
        while(j<=e){
            ans.push_back(nums[j]);
            j++;
        }
        for(int k=s;k<=e;k++){
            nums[k]=ans[k-s];
        }
        return count;
    }

    int reverse_count(vector<int> &nums,int s,int e){
        if(s>=e){
            return 0;
        }
        int mid = (s+e)/2;
        int l_count = reverse_count(nums,s,mid);
        int r_count = reverse_count(nums,mid+1,e);
        int s_count = merge_count(nums,s,e);
        return (l_count+r_count+s_count);
    }

    int reversePairs(vector<int>& nums) {
        int res = reverse_count(nums,0,nums.size()-1);
        return res;
    }
};