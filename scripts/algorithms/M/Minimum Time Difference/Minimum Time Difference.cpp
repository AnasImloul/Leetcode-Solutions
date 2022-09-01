// Runtime: 156 ms (Top 5.09%) | Memory: 13.4 MB (Top 68.16%)
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        unordered_set<string> st;
        for(auto &i: timePoints)
        {
            if(st.count(i)) return 0;
            st.insert(i);
        }
        int ans = INT_MAX;
        int first = -1,prev = 0; // first variable will take the diffrence of the first time stamp given in the input and 00:00
        int hour = 0, minute = 0;
        while(hour<24)
        {
            minute=0;
            while(minute < 60)
            {
                string hh = to_string(hour), mm = to_string(minute);
                if(hh.size() == 1) hh = '0' + hh;
                if(mm.size() == 1) mm = '0' + mm;
                string p = hh + ":"+ mm;
                if(st.count(p))
                {
                    if(first == -1){first = prev;}
                    else
                    {
                        ans = min(ans,prev);
                    }
                    prev = 0;
                }
                prev++;
                minute++;
            }
            hour++;
        }
        ans = min(first+prev,ans);
        return ans;
    }
};