// Runtime: 58 ms (Top 86.01%) | Memory: 11.8 MB (Top 16.62%)
class Solution {
public:

    bool checkIfCanBreak(string s1, string s2)
    {
       vector<int>freq1(26,0),freq2(26,0);
        for(int i=0;i<s1.size();i++)
        {
            freq1[s1[i]-'a']++;
        }
        for(int i=0;i<s2.size();i++)
        {
            freq2[s2[i]-'a']++;
        }
        int count1 =0,count2=0;
        bool check1 = true,check2=true;
        for(int i=0;i<25;i++)
        {
            count1 += freq1[i]-freq2[i];
            count2 += freq2[i] - freq1[i];
            if(count1<0)
            {
                check1 = false;
            }
            if(count2<0)
            {
                check2 = false;
            }
            if(count1<0 && count2<0)
            {
                break;
            }
        }
        return check1 || check2;
    }
};