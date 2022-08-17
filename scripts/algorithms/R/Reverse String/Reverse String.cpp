class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = -1, j = s.size();
        while (++i < --j){
            //Instead of using temp we can do the following
            s[i] = s[j] + s[i];
            s[j] = s[i] - s[j];
            s[i] = s[i] - s[j];
        }
    }
};
