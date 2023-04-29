class Solution {
public:
    int gcd(int a,int b)
    {
        while(a>0 && b>0)
        {
            if(a>b) a=a%b;
            else b=b%a;
        }
        return (a==0? b:a);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> mp;
        vector<int> v;
        for(auto i:deck)
        {
            mp[i]++;
        }
        for(auto it:mp)
        {
            v.push_back(it.second);
        }
        int g=-1;
        for(int i=0;i<v.size();i++)
        {
            if(g==-1)
                g=v[i];
            else 
                g=gcd(g,v[i]);
        }
        return g>1;
    }
};