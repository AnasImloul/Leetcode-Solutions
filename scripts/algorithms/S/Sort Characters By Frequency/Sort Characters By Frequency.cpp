// Runtime: 22 ms (Top 36.06%) | Memory: 8.5 MB (Top 65.22%)
class Solution {
public:
    string frequencySort(string s)
    {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) //get the frequency of every char of the string
        {
            mp[s[i]]++;
        }

        priority_queue<pair<int,char>>pq; //store the freq and char pair in max heap
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({it->second,it->first});
        }
        string str="";
        int val;
        while(!pq.empty())
        {
            val=pq.top().first; //append the char frequency times
            while(val--)
            {
                str.push_back(pq.top().second);
            }
            pq.pop();
        }
        return str;

    }
};
