class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res; //output

        for(int i = 0 ; i < words.size(); i++)
        {
            for(int j = 0; j < words.size(); j++)
            {
                if(i != j && words[j].find(words[i]) != -1)
                {
                    if(!count(res.begin(),res.end(), words[i])) //if vector result does not include this string, push it to vector
                        res.push_back(words[i]);
                    else
                        continue; //if vector result includes this string, ignore
                }
            }
        }
        
        return res;
    }
};
