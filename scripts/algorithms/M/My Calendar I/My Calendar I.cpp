// Runtime: 195 ms (Top 40.35%) | Memory: 37.6 MB (Top 80.95%)
class MyCalendar {
public:
    vector<pair<int,int>>cal;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for(int i=0;i<cal.size();i++){
            if(end<=cal[i].first || start>=cal[i].second)continue;
            else return false;
        }
        cal.push_back({start,end});
        return true;
    }
};