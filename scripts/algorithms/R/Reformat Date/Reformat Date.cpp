class Solution {
    inline static unordered_map<string, string> u{{"Jan", "01"}, {"Feb","02"}, {"Mar","03"}, {"Apr","04"}, {"May","05"}, {"Jun","06"}, {"Jul","07"}, {"Aug","08"}, {"Sep","09"}, {"Oct","10"}, {"Nov","11"}, {"Dec","12"}};
public:
    string reformatDate(string date) {
        if (!isdigit(date[1])) date.insert(0, "0");
        return date.substr(9) + '-' + u[date.substr(5, 3)] + '-' + date.substr(0,2);
    }
};
