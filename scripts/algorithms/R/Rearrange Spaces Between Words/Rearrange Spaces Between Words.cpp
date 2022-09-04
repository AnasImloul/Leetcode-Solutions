// Runtime: 4 ms (Top 33.02%) | Memory: 6.1 MB (Top 81.73%)
class Solution {
public:
    string reorderSpaces(string text) {
       int ct=0;

       // Collection of words
        vector<string> v;
        for (int i=0; i<text.size(); i++){

            // Calculate the numbert of spaces
            while(i<text.size() && text[i] == ' '){
                ct++;
                i++;
            }

            // Extract the words and collect them
            string tp="";
            while(i<text.size() && text[i] != ' '){
                tp+=text[i];
                i++;
            }
            i--;

            // Adding word to the collection
            if(tp.size()) v.push_back(tp);
        }

        text = "";

        // Combining the words with equal number of white spaces
        for(int i=0; i<v.size()-1; i++){
            text += v[i];
            int j=ct/(v.size()-1);
            while(j--) text += ' ';
        }

        text += v[v.size()-1];

        // Adding remaining extra spaces at the end
        int j=(v.size() > 1)?ct % (v.size()-1):ct;
        while(j--) text += ' ';

        return text;
    }
};