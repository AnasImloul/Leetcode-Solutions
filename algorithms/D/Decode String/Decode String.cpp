class Solution {
public:
    string decodeString(string s) {
        stack<string> strstk;
        stack<int> freq;
        string curstr;
        int k=0;
        for(char c:s)
        {
            if(isdigit(c))
                k=k*10+(c-'0');
            else if(isalpha(c))
                curstr.push_back(c);
            else if(c=='[')
            {
                freq.push(k);
                strstk.push(curstr);
                curstr.clear();
                k=0;
            }
            else if(c==']')
            {
                string temp=curstr;
                curstr=strstk.top();
                strstk.pop();
                int fre=freq.top();
                freq.pop();
                while(fre--)
                {
                    curstr+=temp;
                }
            }
        }
        return curstr;
    }
};
