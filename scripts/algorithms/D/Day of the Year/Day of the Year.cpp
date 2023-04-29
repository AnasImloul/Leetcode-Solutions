class Solution {
public:
    bool leapyear(int year){
        return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    }
        
    int dayOfYear(string date) {
        vector<int> v;
        int ans = 0;
        int n = date.length();
        for (int i = 0; i < n; i++) {
            if (date[i] >= '0' && date[i] <= '9') {
                ans = ans * 10 + (date[i] - '0'); // subtract '0' to get the integer value
            } else {
                v.push_back(ans);
                ans = 0;
            }
        }
        v.push_back(ans); // add the last value to the vector
        if (v.size() != 3) return -1; // error handling for invalid input
        int year = v[0];
        int month = v[1];
        int day = v[2];
        if (month == 1) return day;
        if (month == 2) return 31 + day;
       
        if (month == 3) return leapyear(year) ? 60 + day : 59 + day;
         if (month == 4) return leapyear(year) ? 91 + day : 90 + day;
         if (month == 5) return leapyear(year) ? 121 + day : 120 + day;
         if (month == 6) return leapyear(year) ? 152 + day : 151 + day;
         if (month == 7) return leapyear(year) ? 182 + day : 181 + day;
         if (month == 8) return leapyear(year) ? 213 + day : 212 + day;
         if (month == 9) return leapyear(year) ? 244 + day : 243 + day;
         if (month == 10) return leapyear(year) ? 274+ day : 273 + day;
         if (month == 11) return leapyear(year) ? 305 + day : 304 + day;
         if (month == 12) return leapyear(year) ? 335 + day : 334 + day;
        return -1;
    }
};




















