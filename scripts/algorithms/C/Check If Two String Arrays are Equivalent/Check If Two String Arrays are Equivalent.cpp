class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        int wordIdx1 = 0, wordIdx2 = 0, chIdx1 = 0, chIdx2 = 0;
        while(true)
        {
            char ch1 = word1[wordIdx1][chIdx1];
            char ch2 = word2[wordIdx2][chIdx2];
            if (ch1 != ch2) return false;
            
            chIdx1++; //incrementing the character index of current word from "word1"
            chIdx2++; //incrementing the character index of current word from "word2";
            //=========================================================
            if (chIdx1 == word1[wordIdx1].size()) //if current word from "word1" is over
            { 
                wordIdx1++;  //move to next word in "word1"
                chIdx1 = 0;  //reset character index to 0
            }
            if (chIdx2 == word2[wordIdx2].size()) //if  current word from "word2" is over
            { 
                wordIdx2++;  //move to next word  in "word2"
                chIdx2 = 0; //reset character index to 0
            }
            //=================================================================
            if (wordIdx1 == word1.size() && wordIdx2 == word2.size()) break; // words in both arrays are finished
            
            if (wordIdx1 == word1.size() || wordIdx2 == word2.size()) return false;
            //if words in any onr of the arrays are finished and other still has some words in it
            //then there is no way same string could be formed on concatenation
        }
        return true; 
    }
};