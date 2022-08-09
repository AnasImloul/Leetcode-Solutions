class Solution {
public:
    
    // Basically get the length of a repeated sequence starting at pointer p. 
    int getRepeatedLen(string& s, int p) {
        int res = 0; 
        char c = s[p]; 
        while(p < s.size() && s[p] == c) {
            res++;
            p++;
        }
        return res; 
    }
    
    // Check if a word t is stretchy. i.e. can we turn word t into word s? 
    bool isStretchy(string& s, string& t, unordered_set<char>& sMap) {
        if(s == t) return true; 
        if(s.size() < t.size()) return false; // If t is bigger than the original string, return false since we can't take away characters. 
        int p1 = 0; // The first pointer will point to a char in our original string. 
        int p2 = 0; // The second pointer will point to a char in the word we want to stretch. 
        
        // Loop though the target string since we know it was to be either the same length or longer. i.e. "heeellooo" is longer than "hello". 
        while(p1 < s.size()) {
            if(!sMap.count(t[p2])) return false; // If we find a char in the word we want to stretch that's not even in our original string, we return false since we cannot remove chars. 
            int want = getRepeatedLen(s,p1); // For every new char we encounter we check how many are in the orignal string. 
            int have = getRepeatedLen(t,p2); 
            if( have > want) return false;  // Remember can't delete chars. 
            int needToAdd = want - have; 
            if(want != have && needToAdd + have < 3) return false; // If we need to add some chars, we have to also check if the new group size that we create follows our rules of being greater or equal to 3. 
            p1 += want; // We don't want to repeat a char again. 
            p2 += have; // Same as above but for the other word. 
        }
        return true; 
    }
    
    int expressiveWords(string s, vector<string>& words) {
        int res = 0; 
        unordered_set<char> sMap(s.begin(),s.end()); // Useful to know what characters exits in the first place. 
        // Basically loop through every word in the vector and check if it is stretchy. 
        for(string& w : words) {
            if(isStretchy(s,w,sMap)) res++; 
        }
        return res;
    }
};
