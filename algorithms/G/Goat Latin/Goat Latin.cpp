class Solution {
public:
    string toGoatLatin(string sentence) {
        sentence += ' ';
        vector<string> Words;
        string TEMP, SOL, A = "a";
        for (int i = 0; i < sentence.size(); ++i)
        {
            if (sentence[i] == ' ')
            {
                Words.push_back(TEMP);
                TEMP = "";
            }
            else
                TEMP += sentence[i];
        }
        for (string V : Words)
        {
            char TMP = tolower(V[0]);
            if (TMP == 'a' || TMP == 'e' || TMP == 'i' || TMP == 'o' || TMP == 'u')
                V += "ma";
            else
            {
                TMP = V[0];
                V.erase(0, 1);
                V += TMP;
                V += "ma";
            }
            V += A;
            A += 'a';
            SOL += V + ' ';
        }
        SOL.erase(SOL.size() - 1, 1);
        return SOL;
    }
};
