class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<unordered_set<char>> st;
        int res =0;
        for(string s : words){
            unordered_set<char> temp;
            for(char c : s){
                temp.insert(c);
            }
            st.push_back(temp);
        }
        for(int i = 0;i<words.size();i++){
            for(int j =0;j<i;j++){
                bool flag = false;
                for(auto val : st[i]){
                    if(st[j].find(val) != st[j].end()){
                        flag = true;
                        break;
                    }
                }
                if(flag == false) {
                    int prd = words[i].length() * words[j].length();
                    res =max(res, prd);
                }
            }
        }
        return res;
    }
};
