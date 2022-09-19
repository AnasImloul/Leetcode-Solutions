// Runtime: 7 ms (Top 10.31%) | Memory: 6 MB (Top 66.23%)
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();

        //if the first letter of the string is lower-case
        if(islower(word[0])){
            int c = 0;
            for(int i=0; i<n; i++){
                if(islower(word[i])){
                    c++;
                }
            }

            //total lower-case count must be equal to the size of the string
            if(c == n){
                return true;
            }
            return false;
        }

        //if the first letter of the string is upper-case.
        else{
            int c = 0;
            for(int i=0; i<n; i++){
                if(isupper(word[i])){
                    c++;
                }
            }

            //count of total upper-case letters must be equal to 1 or to the size of the string.
            if(c == 1 or c == n){
                return true;
            }

            //in all other cases, return false.
            return false;
        }
    }
};