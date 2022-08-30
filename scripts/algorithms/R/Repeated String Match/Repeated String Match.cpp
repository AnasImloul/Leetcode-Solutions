// Runtime: 246 ms (Top 22.18%) | Memory: 480.2 MB (Top 5.04%)
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int m=a.size(); int n=b.size();
        vector<int>d; int mod=n%m; int h=n/m;

        if(mod==0)
        {d.push_back(h); d.push_back(h+1); }
        else
        { d.push_back(h+1); d.push_back(h+2); }
        string s=""; string t="";

        for(int i=0;i<d[0];i++)
        {s+=a;}
        for(int i=0;i<d[1];i++)
        {t+=a;}

        int i=0; int y1=s.size()-n; int y2=t.size()-n;

        while(i<=y1)
        {
            string x=s.substr(i,n); //cout<<x;
            if(x==b){return d[0]; break;}
            i++;
        }
        i=0;
        while(i<=y2)
        {
            string x=t.substr(i,n); //cout<<"ok1"<<x;
            if(x==b){return d[1]; break;}
            i++;
        }
        return -1;

    }
};