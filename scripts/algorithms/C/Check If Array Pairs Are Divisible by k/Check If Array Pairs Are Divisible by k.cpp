// Runtime: 377 ms (Top 24.57%) | Memory: 76 MB (Top 31.59%)

//ask the interviewer
//can we have negative values?

class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        unordered_map<int,int>memo;//remainder : occurence

        //we are storing the frequency of curr%k
        //i.e. the frequency of the remainder
        for(auto curr : arr)
        {
            int remainder = ((curr%k)+k)%k;
            memo[remainder]++;
        }

        for(int i =1; i<=k/2; i++)
        {
            if(memo[i] != memo[k-i])
                return false;
        }
        if(memo[0]%2 != 0)
            return false;
        return true;
    }
};
