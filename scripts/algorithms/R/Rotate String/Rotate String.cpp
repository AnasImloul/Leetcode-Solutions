class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()){
            return false;
        }
        string temp=s+s;
        if(temp.find(goal)!=-1){
            return true;
        }
        return false;
    }
};