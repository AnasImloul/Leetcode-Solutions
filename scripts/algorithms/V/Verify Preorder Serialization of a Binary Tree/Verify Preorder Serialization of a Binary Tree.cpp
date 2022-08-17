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
