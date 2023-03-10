class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        if(s == target) return true;
        int count1=0,count2=0;
        for(int i=0;i<s.length();i++)
        if(s[i]=='0') count1++; 
        if(count1==s.length()) return false;
         for(int i=0;i<target.length();i++)
        if(target[i]=='0') count2++; 
        if(count2==target.length()) return false;
        return true;
    }
};