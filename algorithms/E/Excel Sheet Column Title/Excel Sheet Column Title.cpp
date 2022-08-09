class Solution {
public:
    string convertToTitle(int columnNumber) {
        string s = "";
        while(columnNumber){
            char c = (columnNumber-1)%26+65;
            s = c+s;
            columnNumber = (columnNumber-1)/26;
        }
        return s;
    }
};
