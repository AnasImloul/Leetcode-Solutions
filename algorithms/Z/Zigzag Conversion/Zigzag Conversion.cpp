class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> v(numRows);
        int j=0,t=1;
        if(numRows ==1)
            return s;
        for(int i=0;i<s.size();i++)
        {
            v[j].push_back((char)s[i]);
            if(j==numRows-1 )
                t=0;
            else if(j==0)
                t=1;
            if(t)
                j++;
            else
                j--;
            
        }
        string x="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<v[i].size();j++)
                x.push_back(v[i][j]);
        }
        return x;
    }
};
