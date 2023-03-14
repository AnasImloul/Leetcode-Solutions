class Solution {
public:
    
    string longestNiceSubstring(string s) {
        int arr1[26]={};
        int arr2[26]={};
        if(s.length()<2)
            return "";
        for(char ch:s)
        {
            if(ch>='A' && ch<='Z')
                arr1[(ch|32)-'a']++;
            else
                arr2[ch-'a']++;
        }
        vector<int> index;
        index.push_back(-1);
        for(int i=0;i<s.length();i++)
        {
            if((arr1[(s[i]|32)-'a']>=1 && arr2[(s[i]|32)-'a']==0) || (arr1[(s[i]|32)-'a']==0 && arr2[(s[i]|32)-'a']>=1))
                index.push_back(i);
        }
        //index.push_back(2);
        index.push_back(s.length());
        if(index.size()==2)
            return s;
        string minn="";
        for(int i=0;i<index.size()-1;i++)
        {
            string temp = longestNiceSubstring(s.substr(index[i]+1,index[i+1]-index[i]-1));
            minn = temp.length()>minn.length()?temp:minn;
        }
        return minn;
    }
};