class Solution {
public:
    long long numberOfWays(string s) {
        long long a=0,b=0,ans=0;        // a and b are the number of occurances of '1' and '0' after the current building respectively.
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                a++;
            else
                b++;
        }
        long long c=0,d=0;              // c and d are the number of occurances of '1' and '0' before the current building respectively.
        for(int i=0;i<s.length();i++){
            if(s[i]=='1'){               // Counting the sequences of "010"
                ans+=(d*b);
                a--;
                c++;
            }
            else{                        // Counting the sequences of "101"
                ans+=(a*c);
                b--;
                d++;
            }
        }
        return ans;
    }
};
