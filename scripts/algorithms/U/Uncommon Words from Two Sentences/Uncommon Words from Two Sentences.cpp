class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
      int i=0,temp;
      map<string,int> m;
      while(i<s1.length())
      {
          temp=i;
          while(i<s1.length() && s1[i]!=' ')
          {
              i++;
          }
          if(m.find(s1.substr(temp,i-temp))==m.end())
          {
          m[s1.substr(temp,i-temp)]=1;
          }
          else
          {
            m[s1.substr(temp,i-temp)]++;
          }
          i++;
      }  
    int j=0;
    int t;
    vector<string> ans;
    while(j<s2.length())
    {
       t=j;
       while(j<s2.length() && s2[j]!=' ')
        {
              j++;
        }
      if(m.find(s2.substr(t,j-t))!=m.end())
      {
         m[s2.substr(t,j-t)]++;
      }
      else
      {
        m[s2.substr(t,j-t)]=1;
      }
      j++;
    }
    map<string,int>::iterator itr;
    for(itr=m.begin();itr!=m.end();itr++)
    {
      if(itr->second<2)
      {
      ans.push_back(itr->first);
      }
    }
    return ans;
}
};