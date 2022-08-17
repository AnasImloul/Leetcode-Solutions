class Solution 
{
public:
    char repeatedCharacter(string s) 
    {
        unordered_map<char, int> mp; //for storing occurrences of char
        
        char ans;
        for(auto it:s)
        {
            if(mp.find(it) != mp.end()) //any char which comes twice first will be the ans; 
            {
                ans = it;
                break;
            }
            mp[it]++; //increase the count of char
        }
        return ans;
    }
};
