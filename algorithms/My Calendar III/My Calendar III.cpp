class MyCalendarThree {
public:
    map<int,int>mp;
    MyCalendarThree() {   
    }
    int book(int start, int end) {
        mp[start]++;
        mp[end]--;
        int sum = 0;
        int ans = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            sum += it->second;
            ans = max(ans,sum);
        }
        return ans;
    }
};
