class Solution {
public:
    int longestDecomposition(string text) {
        if(text.size() == 0)
            return 0;
        int i = 0;
        deque<char> sFront;
        deque<char> sBack;
        while(i < text.size() / 2){
            sFront.push_back(text[i]);
            sBack.push_front(text[text.size() - 1 - i]);
            if(sFront == sBack)
                return 2 + longestDecomposition(text.substr(i + 1, text.size() - 2*(i+1)));
            i++;
        }
        return 1;
    }
};
