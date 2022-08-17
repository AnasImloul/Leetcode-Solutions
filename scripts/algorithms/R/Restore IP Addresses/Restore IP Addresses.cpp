class Solution {
public:
    vector<string> res;
    void dfs(string s,int idx,string curr_ip,int cnt)
    {
        if(cnt>4)
            return;
        if(cnt==4&&idx==s.size())
        {
            res.push_back(curr_ip);
           // return;
        }
        for(int i=1;i<4;i++)
        {
            if(idx+i>s.size())
                break;
            string str=s.substr(idx,i);
            if((str[0]=='0'&&str.size()>1)||(i==3&&stoi(str)>=256))
                continue;
            dfs(s,idx+i,curr_ip+str+(cnt==3?"":"."),cnt+1);
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        dfs(s,0,"",0);
        return res;
        
        
    }
};
