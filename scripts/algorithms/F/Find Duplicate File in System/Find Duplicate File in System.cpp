// Runtime: 69 ms (Top 94.12%) | Memory: 34.30 MB (Top 96.57%)

class Solution
{
public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for (auto &s : paths)
        {
            string startPath;
            bool firstSpace = true;
            for (int i = 0; i < s.size(); i++)
            {

                if (firstSpace){
                    startPath += s[i];
                }

                if (firstSpace && s[i] == ' ')
                {
                    firstSpace = false;
                    startPath.pop_back();
                }

                if (s[i] == ' ')
                {
                    i++;
                    string fileName;
                    
                    while (s[i] != '(')
                    {
                        fileName += s[i++];
                    }

                    i++;
                    string fileContent;

                    while (s[i] != ')')
                    {
                        fileContent += s[i++];
                    }

                    map[fileContent].push_back(startPath + '/' + fileName);
                }
            }
        }
        for (auto &i : map)
        {
            if (i.second.size() > 1)
            {
                ans.push_back(i.second);
            }
        }
        return ans;
    };
};
