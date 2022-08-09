class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char,int> mp;
        int size=croakOfFrogs.size();
        
        for(int i=0;i<size;i++)
        {
            mp[croakOfFrogs[i]]++;
            if(mp['c']<mp['r'] || mp['r']<mp['o'] || mp['o']<mp['a'] || mp['a']<mp['k'])
                return -1;
        }
        
        int count=mp[croakOfFrogs[0]];
        for(auto i:croakOfFrogs)
        {
            if(count!=mp[i])
                return -1;
        }
        
        int ans=0;
        int i=0;
        int temp=0;
        
        for(i=0;i<size;i++)
        {
            if(croakOfFrogs[i]=='c')
            {
                temp++;
            }
            else if(croakOfFrogs[i]=='k')
            {
                temp--;
            }
            if(temp>ans)
                ans=temp;
        }
        return ans;
    }
};