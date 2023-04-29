class Solution {
public:
    bool checkRecord(string s);
};
/*********************************************************/
bool Solution::checkRecord(string s) {
    int i, size = s.size(), maxL=0, countA=0, countL=0;
    for (i = 0; i < size; ++i) {
        if (s[i] == 'L') {
            ++countL;
        } else {
            countL = 0;
        }
        if (s[i] == 'A') {
            ++countA;
        }
        if (maxL < countL) {
            maxL = countL;
        }
        if( countA >= 2 || maxL >= 3) {
            return false;
        }
    }
    return true;
}
/*********************************************************/