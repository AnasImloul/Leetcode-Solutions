class Solution {
public:
    //In case string is duplicated, check if string has any duplicate letters
    bool dupeCase(string s){
        unordered_set<char> letters;
        for(auto it : s){
            if(letters.count(it)){  //Found dupe letter (they can be swapped)
                return true;
            } else {
                letters.insert(it);
            }
        }
        return false;   //all letters unique
    }
    
    bool buddyStrings(string s, string goal) {
        //check len
        if(goal.length() != s.length()) return false;
        //If strings are the same, use diff. method
        if(s == goal) return dupeCase(s);
        //Track index of differences 
        vector<int> diff;
        for(int i = 0; i < s.length(); i++){
            if(s[i] != goal[i]){    //If diff found
                if(diff.size() > 2){    //If this is third diff, return false
                    return false;
                } else {            //If not store in diff array
                    diff.push_back(i);
                }
            }
        }
        //If only one diff found, return false
        if(diff.size() == 1) return false;
        //else return if swap works
        return (s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]);
    }
};
