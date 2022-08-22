// Runtime: 1363 ms (Top 43.98%) | Memory: 241.8 MB (Top 81.02%)
class Solution {
public:

    int waysToPartition(vector<int>& nums, int k) {
        unordered_map<long long int,int> left;
        unordered_map<long long int,int> right;

        long long int sum=accumulate(nums.begin(),nums.end(),0L);
        long long int leftSum=0;
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            leftSum+=nums[i];
            long long int rightSum=sum-leftSum;
            long long int difference=leftSum-rightSum;
            right[difference]++; //storing difference count in right, since no difference exist in left
        }

        int res=right[0]; // Point Zero difference are the partition points
        leftSum=0;
        for(int i=0;i<n;i++){
            long long int D=k-nums[i];
            res=max(res,right[-D]+left[D]); // We can run a few test cases and see that if we replace arr[i] by k, the difference D, the left side including i,each element decreases by D while the right Side each element increases by D, so we find -D on right Side... WHY?? if right side is increasing by D, we need to find -D since this will result in -D+D=0, which are our partition points, since point 0 signifies a partition where leftSum==rightSum, similarly, left side decreases by D, so we find +D on left since this will result in zero as well.

            leftSum+=nums[i];
            long long int rightSum=sum-leftSum;
            left[leftSum-rightSum]++; //Now since we are moving our i forward, we are gonna change the next i point, so we are placing leftSum-RightSum on left side
            right[leftSum-rightSum]--; // From right we are gonna decrease it and transfer to left side
            if(right[leftSum-rightSum]==0){
                right.erase(leftSum-rightSum);
            }
        }
        return res;
    }
};