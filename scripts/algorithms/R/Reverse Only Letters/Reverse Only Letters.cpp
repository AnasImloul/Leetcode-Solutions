// Runtime: 3 ms (Top 43.65%) | Memory: 6.1 MB (Top 17.51%)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int a=0,b=s.size()-1;
        for(;a<b;)
        {
            if(((s[a]>='a'&&s[a]<='z')||(s[a]>='A'&&s[a]<='Z'))&&((s[b]>='a'&&s[b]<='z')||(s[b]>='A'&&s[b]<='Z')))
               {
                   char z=s[a];
                   s[a]=s[b];
                   s[b]=z;
                   a++;
                   b--;
               }
               else if(!((s[a]>='a'&&s[a]<='z')||(s[a]>='A'&&s[a]<='Z'))&&((s[b]>='a'&&s[b]<='z')||(s[b]>='A'&&s[b]<='Z')))
                       {
                           a++;
                       }
                       else if(((s[a]>='a'&&s[a]<='z')||(s[a]>='A'&&s[a]<='Z'))&&!((s[b]>='a'&&s[b]<='z')||(s[b]>='A'&&s[b]<='Z')))
                       b--;
                       else{
                           a++;
                           b--;
                       }

    }
        return s;
    }
};