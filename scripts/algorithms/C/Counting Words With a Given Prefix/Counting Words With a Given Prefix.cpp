// Runtime: 7 ms (Top 81.4%) | Memory: 10.90 MB (Top 13.89%)

// The easiest solution to this problem is:
// Step 1: Calculate length of "pref"
// Step 2: find substring of "words" from 0 to length of "pref"
// if both match increment count by 1;



class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int count=0;
        int preflen=pref.size();        //step 1
        
        for(auto i:words){
            if(i.substr(0,preflen) == pref)     //step 2
                count++;                        //if both matches then increment count by 1
            
        }
        return count;   //return count
        
    }
};
