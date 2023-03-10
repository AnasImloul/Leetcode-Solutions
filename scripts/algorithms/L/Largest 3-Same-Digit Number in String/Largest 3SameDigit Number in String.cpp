class Solution {
public:
    string largestGoodInteger(string num) {
        
        for(int i='9';i>='0';i--){
            string s;
            s+=i;
            s+=i;
            s+=i;
            //S will be 999 or 888 or 777 or 666 or 555 or 444 or 333 or 222 or 111 or 000
            if(num.find(s)!=string::npos)
                return s;
        }
        return "";
    }
};