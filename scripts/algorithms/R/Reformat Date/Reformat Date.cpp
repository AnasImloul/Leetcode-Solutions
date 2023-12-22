// Runtime: 0 ms (Top 100.0%) | Memory: 6.50 MB (Top 57.94%)

class Solution {
public:
    string reformatDate(string date) {
        // easiest way to get index with O(1)
        unordered_map<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},{"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},{"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        istringstream s(date); 
        // get day
        string day; s >> day;
        day.pop_back(); day.pop_back();
        if (day.size() == 1)
            day = "0" + day;
        // get month
        string month; s >> month;
        // get year
        string year; s >> year;
        return year + "-" + months[month] + "-" + day;
    }
};
