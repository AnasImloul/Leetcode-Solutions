// Runtime: 10 ms (Top 30.76%) | Memory: 6.8 MB (Top 63.53%)
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream s(preorder);
        string str;
        int slots=1;
        while(getline(s, str, ',')) {
            if(slots==0) return 0;
            if(str=="#") slots--;
            else slots++;
        }
        return slots==0;
    }
};