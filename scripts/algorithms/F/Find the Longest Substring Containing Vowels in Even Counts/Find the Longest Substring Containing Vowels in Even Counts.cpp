// Runtime: 212 ms (Top 38.91%) | Memory: 16.2 MB (Top 66.09%)

//When the xor of all the even times numbers are done it results in 0. The xor of the vowels are done by indicating
//them with a single digit and the xor value is stored in a map
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int x= 0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        int n=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                x^= (s[i]-'a'+1);
               if(mp.find(x)==mp.end())
                  mp[x]=i;
            }
            if(mp.find(x)!=mp.end())
                n= max(n,i-mp[x]);
        }
        return n;
    }
};