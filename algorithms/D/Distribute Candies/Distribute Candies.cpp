class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        unordered_set<int> s(candyType.begin(),candyType.end());
        return min(candyType.size()/2,s.size());
            
        
    }
};
//if you like the solution plz upvote.