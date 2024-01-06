// Runtime: 0 ms (Top 100.0%) | Memory: 7.10 MB (Top 30.21%)

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<int> ch(26,0);
        //store the broken letters
        for(char c: brokenLetters){
            ch[c-'a']=1;
        }
        // breaking text into word using string stream
        stringstream s(text); // Used for breaking words
        string word; // to store individual words
  
        int count = 0,flag=0;
        while (s >> word){
            flag=0;
            for(char &c: word){
                //if the word contains a broken letter mark flag=1
                if(ch[c-'a']==1){
                    flag=1;
                    break;
                }
            }
            //if flag is 0 which means that there is no broken letter in word so increase the count
            if(flag==0)
                count++;
        }
        return count;
    }
};
