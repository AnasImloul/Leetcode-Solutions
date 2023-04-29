class Solution {
public:
    int addMinimum(string word) {
        word += "  ";
        int ans = 0;
        for(int i = 0; i < word.size() - 2; i++) {
            int c = word[i];
            if(c == 'a') {
                if(word[i + 1] == 'b') {
                    i++;
                    if(word[i + 1] == 'c') {
                        i++;
                    } else {
                        ans++;
                    }
                } else if(word[i + 1] == 'c'){
                    i++;
                    ++ans;
                } else {
                    ans += 2;
                }
            } else if(c == 'b') {
                if(word[i + 1] == 'c') {
                    i++;
                    ++ans;
                } else {
                    ans += 2;
                }
            } else if(c == 'c') {
                ans += 2;
            }
        }
        return ans;
    }
};