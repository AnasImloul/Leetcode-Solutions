class Solution {
public:
    int numPermsDISequence(string s) {
        int n=s.length();
        queue<pair<string,unordered_set<int>>> q;
        unordered_set<int> v;
        string str="";
        for(int i=0;i<=n;++i)
        {
            str="";
            v.clear();
            str+=(i+'0');
            v.insert(i);
            q.push({str,v});
        }
        int i=0;
        unordered_set<string> visall;
        while(!q.empty())
        {
            int sz=q.size();
            if(i==n)
            {
                return q.size();
            }
            while(sz--)
            {
                auto temp=q.front();
                q.pop();
                if(visall.find(temp.first)!=visall.end())
                {
                    continue;
                }
                if(s[i]=='D')
                {
                    for(int j=temp.first.back()-'0'-1;j>=0;--j)
                    {
                        if(temp.second.find(j)==temp.second.end())
                        {
                            temp.first+=(j+'0');
                            temp.second.insert(j);
                            if(visall.find(temp.first)==visall.end())
                            {
                                q.push({temp.first,temp.second});
                            }
                            temp.second.erase(j);
                            temp.first.pop_back();
                        }
                    }
            }
                else
                {
                    for(int j=temp.first.back()-'0'+1;j<=n;++j)
                    {
                        if(temp.second.find(j)==temp.second.end())
                        {
                            temp.first+=(j+'0');
                            temp.second.insert(j);
                            if(visall.find(temp.first)==visall.end())
                            {
                                q.push({temp.first,temp.second});
                            }
                            temp.second.erase(j);
                            temp.first.pop_back();
                        }
                    }
                }
            }
            i++;
        }
        return 0;
    }
};
