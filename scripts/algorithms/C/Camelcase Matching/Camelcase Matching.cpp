class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        
        vector<bool> res(queries.size());
        
        for (int i = 0; i < queries.size(); i++)
        {
            int patRef = 0;
            bool isCamel = true;
            
            for (const char& ltr : queries[i])
            {
                if (patRef == pattern.size())
                {
                    if (isupper(ltr))
                    {
                        isCamel = false;
                        break;
                    }
                }
                else
                {
                    if (isupper(ltr) and isupper(pattern[patRef]) and ltr != pattern[patRef])
                    {
                        isCamel = false;
                        break;
                    }
                    else if (islower(ltr) and islower(pattern[patRef]) and ltr == pattern[patRef])
                        patRef++;
                    else if (ltr == pattern[patRef])
                        patRef++;
                }
            }
            
            if (patRef == pattern.size() and isCamel)
                res[i] = true;
        }
                             
        return res;
    }
};
