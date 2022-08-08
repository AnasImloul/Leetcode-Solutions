class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> vec1;
        for(int i = 0; i < paths.size(); ++i){
            vector<string> level;
            string temp1 = paths[i];
            string temp2 = "";
            for(int j = 0; j < temp1.length(); ++j){
                if(temp1[j] == ' '){
                    level.push_back(temp2);
                    temp2 = "";
                }
                else
                    temp2 += temp1[j];
                if(j == temp1.length() - 1)
                    level.push_back(temp2);
            }
            vec1.push_back(level);
        }
        unordered_map<string, vector<string>> ump;
        for(int i = 0; i < vec1.size(); ++i){
            string rootDir = vec1[i][0];
            for(int j = 1; j < vec1[i].size(); ++j){
                string str1 = rootDir, str2 = "";
                int pos = -1;
                for(int k = 0; k < vec1[i][j].length(); ++k){
                    if(vec1[i][j][k] == '('){
                        pos = k;
                        break;
                    }
                }
                str1 += '/';
                for(int k = 0; k < pos; ++k)
                    str1 += vec1[i][j][k];
                str2 = vec1[i][j].substr(pos);
                ump[str2].push_back(str1);
            }
        }
        vector<vector<string>> res;
        for(auto it = ump.begin(); it != ump.end(); ++it)
            if(it->second.size() > 1)
                res.push_back(it->second);
        return res;
    }
};
