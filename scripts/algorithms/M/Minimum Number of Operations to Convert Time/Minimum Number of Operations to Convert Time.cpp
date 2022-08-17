class Solution {
public:
    int HHMMToMinutes(string s){
        return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
    }
    int convertTime(string current, string correct) {
        int diff = - HHMMToMinutes(current) +  HHMMToMinutes(correct);
        vector<int> order = {60,15,5,1};
        int i = 0;
        int ans = 0;
        while(i < 4){
            ans+=(diff/order[i]);
            diff%=order[i];
            i++;
        }
        
        return ans;
    }
};
