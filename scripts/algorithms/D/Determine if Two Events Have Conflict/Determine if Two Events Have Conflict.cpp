class Solution {
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2) {
        int start = stoi(event1[0].substr(3)) + stoi(event1[0].substr(0, 2)) * 60;
        int end = stoi(event1[1].substr(3)) + stoi(event1[1].substr(0, 2)) * 60;
        int start1 = stoi(event2[0].substr(3)) + stoi(event2[0].substr(0, 2)) * 60;
        int end1 = stoi(event2[1].substr(3)) + stoi(event2[1].substr(0, 2)) * 60;
        if (start >= start1 && start <= end1){
            return true;
        }
        if (end >= start1 && end <= end1){
            return true;
        }
        if (start1 >= start && start1 <= end){
            return true;
        }
        if (end1 >= start && end1 <= end){
            return true;
        }
        return false;

    }
};