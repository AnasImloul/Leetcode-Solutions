// Runtime: 1696 ms (Top 38.97%) | Memory: 63.6 MB (Top 61.56%)
class Solution {
public:
    void find(vector<int>&v, int i, int e, int sum, vector<int>&sumv){
        if(i==e){
            sumv.push_back(sum);
            return;
        }
        find(v,i+1,e,sum+v[i],sumv);
        find(v,i+1,e,sum,sumv);
    }

    int minAbsDifference(vector<int>& nums, int goal) {
        int n=nums.size();

        //Step 1: Divide nums into 2 subarrays of size n/2 and n-n/2

        vector<int>A,B;
        for(int i=0;i<n/2;i++)
            A.push_back(nums[i]);
        for(int i=n/2;i<n;i++)
            B.push_back(nums[i]);

        //Step 2: Find all possible subset sums of A and B

        vector<int>sumA,sumB;
        find(A,0,A.size(),0,sumA);
        find(B,0,B.size(),0,sumB);

        sort(sumA.begin(),sumA.end());
        sort(sumB.begin(),sumB.end());

        //Step 3: Find combinations from sumA & sumB such that abs(sum-goal) is minimized

        int ans=INT_MAX;

        for(int i=0;i<sumA.size();i++){
            int s=sumA[i];
            int l=0;
            int r=sumB.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                int sum=s+sumB[mid];
                if(sum==goal)
                    return 0;
                ans=min(ans,abs(sum-goal));
                if(sum>goal){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }

        return ans;
    }
};