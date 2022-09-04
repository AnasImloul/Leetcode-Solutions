// Runtime: 24 ms (Top 57.17%) | Memory: 15.9 MB (Top 25.00%)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int siz = letters.size();
        bool isPresent = false;
        char ans;
        char temp = target;

        if (target == letters[siz-1]) return letters[0];

        for(int i=0; i<siz-1; i++) {
            if (target == letters[i] && target != letters[i+1]) {
                ans = letters[i+1];
                isPresent = true;
                break;
            }
        }

        // if target not in letters
        while (!isPresent) {
            temp = temp +1;
            isPresent = binary_search(letters.begin(), letters.end(), temp); // used STL !!
            if(isPresent) {
                ans=temp;
                break;
            }
        }
        return ans;
    }
};