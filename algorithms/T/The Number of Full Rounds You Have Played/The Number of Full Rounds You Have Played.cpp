class Solution {
public:
    int solve(string s)
    {
        int hour=stoi(s.substr(0,2));
        int min=stoi(s.substr(3,5));
        return hour*60+min;
    }
    int numberOfRounds(string loginTime, string logoutTime) {
        int st=solve(loginTime);
        int et=solve(logoutTime);
        int ans=0;
        if(st>et) et=et+1440;
        if(st%15!=0) st=st+(15-st%15);
        ans=(et-st)/15;
        return ans;
    }
};
