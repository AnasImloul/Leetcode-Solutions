// Runtime: 0 ms (Top 100.00%) | Memory: 6.2 MB (Top 69.17%)
class Solution {
public:
    string generateTheString(int n) {
        string s="";
        if(n%2!=0){
            for(int i=0;i<n;i++)
                s+="a";
        }
        else{
            for(int i=0;i<n-1;i++)
                s+="a";
            s+="b";
        }
        return s;
    }
};