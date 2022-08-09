class Solution {
public:
    int dayOfYear(string date) {
        unordered_map<int, int>months{{1,0}, {2,31}, {3,59}, {4,90}, {5,120}, {6,151}, {7,181}, {8,212}, {9,243}, {10,273}, {11,304}, {12,334}};
        int year = getInt(date, 0, 3);
        int mon = getInt(date, 5, 6);
        int day = getInt(date, 8, 9);
        int res = months[mon] + day;
        return (year%4==0 && (year%400 == 0 || year%100 != 0)) && mon > 2 ? res + 1 : res;
    }
    
    int getInt(string &date, int l, int r)
    {
        int num = 0;
        for(int i = l; i<=r; i++)
            num = num*10 + (date[i]-'0');
        return num;
    }
};