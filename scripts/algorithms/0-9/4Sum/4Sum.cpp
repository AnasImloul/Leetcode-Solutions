// Runtime: 259 ms (Top 22.83%) | Memory: 13.2 MB (Top 82.16%)
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<int> > answer;

        if(n<4) return answer;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;){
            for(int j=i+1;j<n;){

                int left = j+1;
                int right = n-1;

                long long int x = (long long int)target - (long long int)nums[i] - (long long int)nums[j];

                while(left<right){

                    if(x == nums[left]+nums[right]){
                    vector<int> vect{nums[i] , nums[j] , nums[left] , nums[right]};
                    answer.push_back(vect);

                    //skipping duplicates while moving right
                    int k = 1;
                    while((left+k)<n && nums[left+k]==nums[left]) ++k;

                    if((left+k)>=n) break;
                    else left = left+k;

                    //skipping duplicates while moving left
                    k = 1;
                    while((right-k)>=0 && nums[right-k]==nums[right]) ++k;

                    if((right-k)<0) break;
                    else right = right-k;

                }
                else{

                    if(x>nums[left]+nums[right]){

                        //skipping duplicates while moving right
                        int k = 1;
                        while((left+k)<n && nums[left+k]==nums[left]) ++k;

                        if((left+k)>=n) break;
                        else left = left+k;

                    }
                    else{

                        //skipping duplicates while moving left
                        int k = 1;
                        while((right-k)>=0 && nums[right-k]==nums[right]) ++k;

                        if((right-k)<0) break;
                        else right = right-k;

                    }

                }

                }

               //skipping duplicates while moving right
               int k = 1;
                while((j+k)<n && nums[j+k]==nums[j]) ++k;

                if((j+k)>=n) break;
                else j = j+k;

            }

            //skipping duplicates while moving right
            int k = 1;
            while((i+k)<n && nums[i+k]==nums[i]) ++k;

            if((i+k)>=n) break;
            else i = i+k;
        }

        return answer;
    }
};