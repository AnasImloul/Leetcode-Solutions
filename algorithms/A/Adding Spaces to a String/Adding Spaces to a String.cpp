class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int i,n=spaces.size(),m=s.size(),j;
        string ans="";
        i=0;
        j=0;
        
        //jth pointer for current index of spaces vector
        //ith pointer for current index of our answer string
        while(i<m)
        {
            //if at our current index i is equals to spaces[j] which means we have space at this index,so we add space right here
            if(j<n&&i==spaces[j])
            {
                ans+=" ";
                j++;
                //incrementing j to get next space index location
            }
            ans+=s[i];
            i++;
        }
        
        return ans;
    }
};
