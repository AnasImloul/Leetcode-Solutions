// Runtime: 5 ms (Top 21.01%) | Memory: 6.2 MB (Top 47.48%)
class Solution {
public:
    string reformatNumber(string number) {

        string temp; // stores the digits from string number
        string ans; //stores final answer
        int n = number.size();

        for(auto ch:number)
            if(isdigit(ch)) temp += ch;

        int len = temp.size();
        int i = 0;

        while(len>0){
            //check for different values of "len"
            if(len > 4){ //if len > 4 -> make grp of 3 digits
                ans += temp.substr(i,i+3);
                temp.erase(i,3);
                len = len-3;
                ans += "-";
            }

            else if(len == 3){ //if len == 3 -> make grp of 3 digits
                ans += temp.substr(i,i+3);
                temp.erase(i,3);
                len = len-3;
                ans += "-";
            }

            else if(len == 2){ //if len == 2 -> make grp of 2 digits
                ans += temp.substr(i,i+2);
                temp.erase(i,2);
                len = len-2;
                ans += "-";
            }

            else if(len == 4){ //if len == 4 -> make 1 grp of 2 digits & reduce the length by 2 units, in the next iteration it will automatically catch (len==2) condition
                ans += temp.substr(i,i+2);
                temp.erase(i,2);
                ans += "-";
                // ans += temp.substr(i,i+2); ------(1)
                // temp.erase(i,2); ------(2)
                // ans += "-"; ------(3)
                len = len-2; // *len = len-4* can be edited to *len = len-2*------(4)

            }

        }

        ans.pop_back();
        return ans;
    }
};