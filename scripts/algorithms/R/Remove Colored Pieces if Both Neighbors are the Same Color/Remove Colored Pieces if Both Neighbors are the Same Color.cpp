class Solution {
public:
    bool winnerOfGame(string colors) {
        if (colors.size() < 3) return false;
        int a = 0, b = 0;
        for (int i = 0; i < colors.size()-2; i++) {
            if (colors.substr(i, 3) == "AAA") a++;
            else if (colors.substr(i, 3) == "BBB") b++;
        }
        return a > b;
    }
};
