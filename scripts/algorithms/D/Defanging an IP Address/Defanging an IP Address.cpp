// Runtime: 2 ms (Top 45.49%) | Memory: 5.9 MB (Top 68.62%)
class Solution {
public:
    string defangIPaddr(string address) {
     string res;
        for(int i=0;i<address.length();i++){
         if(address[i]=='.'){
             res+="[.]";

         }
        else{
                res+=address[i];
            }
     }
        return res;
    }
};