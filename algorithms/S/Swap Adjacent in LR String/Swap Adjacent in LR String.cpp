class Solution {
public:
    bool canTransform(string start, string end) {
        int s=0,e=0;
        while(s<=start.size() and e<=end.size()){
            while(s<start.size() and start[s]=='X'){
                s++;
            }
            while(e<end.size() and end[e]=='X'){
                e++;
            }
            if(s==start.size() or e==end.size()){
                return s==start.size() and e==end.size();
            } else if(start[s]!=end[e]){
                return false;
            } else if(start[s]=='R' and e<s){
                return false;
            } else if(start[s]=='L' and e>s){
                return false;
            }
            s++;
            e++;
        }
        return true;
    }
};