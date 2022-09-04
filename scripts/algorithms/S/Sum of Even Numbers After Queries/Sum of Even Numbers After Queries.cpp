// Runtime: 239 ms (Top 12.55%) | Memory: 45.4 MB (Top 84.80%)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    //Sum of all even numbers in the array intially
        int tes=accumulate(nums.begin(),nums.end(),0,[](int curr,int a) {if(a%2==0) return curr+=a;
                else return curr;});
        vector<int> ans(queries.size());
        bool a=false,b=false;
        for(int i=0;i<queries.size();i++)
        {
            //If both are even or odd it stays even then
            a=nums[queries[i][1]]%2==0 && queries[i][0]%2==0;
            b=abs(nums[queries[i][1]]%2)==1 && abs(queries[i][0]%2)==1;
            if(a)
                tes+=queries[i][0];
            else if(b)
                tes+=queries[i][0]+nums[queries[i][1]];
            else if(nums[queries[i][1]]%2==0)
                tes-=nums[queries[i][1]]; //If even turns to odd because of operation remove that even value from ans
            ans[i]=tes; //Adding the result
            nums[queries[i][1]]+=queries[i][0]; //now completing the operation in queries to use in further operations
        }
        return ans;
    }
};