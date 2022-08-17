class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        int ans = 9 >= stol(left) && 9 <= stol(right) ? 1 : 0;
        for (int dig = 1; dig < 10; dig++) {
            bool isOdd = dig % 2 && dig != 1;
            int innerLen = (dig >> 1) - 1,
                innerLim = max(1, (int)pow(2, innerLen)),
                midPos = dig >> 1, midLim = isOdd ? 3 : 1;
            for (int edge = 1; edge < 3; edge++) {
                string pal(dig, '0');
                pal[0] = (char)(edge + 48);
                pal[dig-1] = (char)(edge + 48);
                if (edge == 2) innerLim = 1, midLim = min(midLim, 2);
                for (int inner = 0; inner < innerLim; inner++) {
                    if (inner > 0) {
                        string innerStr = bitset<3>(inner).to_string();
                        innerStr = innerStr.substr(3 - innerLen);
                        for (int i = 0; i < innerLen; i++) {
                            pal[1+i] = innerStr[i];
                            pal[dig-2-i] = innerStr[i];
                        }
                    }
                    for (int mid = 0; mid < midLim; mid++) {
                        if (isOdd) pal[midPos] = (char)(mid + 48);
                        long square = stol(pal) * stol(pal);
                        if (square > stol(right)) return ans;
                        if (square >= stol(left) && isPal(to_string(square))) ans++;
                    }
                }
            }
        }
        return ans;
    }
    
    bool isPal(string str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            if (str[i] != str[j]) return false;
        return true;
    }
};
