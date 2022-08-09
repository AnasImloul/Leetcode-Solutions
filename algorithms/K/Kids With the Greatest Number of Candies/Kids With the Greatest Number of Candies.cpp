class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int i = 0, size, max = 0;
        size = candies.size();
        for(i = 0; i<size; i++){
            if(candies[i]>max) max = candies[i];
        }
        for(i = 0; i<size;i++){
            if(candies[i]+extraCandies >= max){
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
    }
};
