class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int n = s.size();
        map<char,int> mp;
        int count=0;
        while(j<n){
            mp[s[j]]++;
            if(mp.size()<3){
                j++;
            }
            else{
               while(mp.size()==3){
                   count+=(n-j);
                   mp[s[i]]--;
                   if(mp[s[i]]==0) mp.erase(s[i]);
                   i++;
                }
                j++;
            }
        }
        return count;
    }
};
