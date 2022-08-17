class Solution {
public:
    bool halvesAreAlike(string s) {
        unordered_set<char> set = {'a', 'e', 'i', 'o', 'u','A','I','E','O','U'};
        int i=0,j=s.size()/2,cnt=0;
        while(j<s.size()){
            if(set.find(s[i])!=set.end()) cnt++;
            if(set.find(s[j])!=set.end()) cnt--;
            i++;
            j++;
        }
        return cnt==0;
    }
};
