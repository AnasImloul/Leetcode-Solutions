// Runtime: 3 ms (Top 30.23%) | Memory: 5.8 MB (Top 100.00%)
class Solution {
public:
    double toDouble(string s){

       // Strings for each integral, fractional, and repeating part
       string in="", fn="", rn="";

        int i=0;

        // Integral
        while(i<s.size() && s[i]!='.'){ in+=s[i]; i++; }
        // Fractional
        i++;
        while(i<s.size() && s[i]!='('){ fn+=s[i]; i++; }
        // Repeating
        i++;
        while(i<s.size() && s[i]!=')'){ rn+=s[i]; i++; }

         // Number
        double a = 0;

        // Adding integral part
        if(!in.empty()) a=stoi(in);

        i=0;

        // Adding fractional part
        while(i<fn.size()){
            a = a*10 + fn[i] - '0';
            i++;
        }

        // Adding repeating part
        if(i < 8){
            // If repeatig part isn't there then just add 0s
            if(rn.size() == 0){
                while(i <= 8){ a*=10;i++; }
            }

            else {
                int j=0;
                while(i <= 8){
                    a = a*10 + rn[j%rn.size()] - '0';
                    j++;
                    i++;
                }
            }
        }
        // Return number/10^8
        return a/10e8;
    }

    bool isRationalEqual(string s, string t) {
        // Find absolute differance till 8 digits after decimal and compar if its lesser
        double ans = abs(toDouble(s) - toDouble(t));
        return ans < 0.000000002;
    }
};