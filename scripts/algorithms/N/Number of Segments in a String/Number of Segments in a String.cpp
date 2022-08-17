class Solution {
public:
    int countSegments(string s) {
        if(s=="")
            return 0;
        int res=0,flag=0;
        for(int i=0;i<size(s);i++){
            if(s[i]!=' '){
                i++;
                while(i<size(s) and s[i]!=' '){
                    i++;
                }
                res++;
            }
        }
        return res;
    }
};
