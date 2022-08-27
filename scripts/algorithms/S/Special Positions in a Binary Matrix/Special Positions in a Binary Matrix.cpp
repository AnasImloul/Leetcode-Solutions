// Runtime: 67 ms (Top 10.18%) | Memory: 18.5 MB (Top 5.36%)
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<vector<int>>v;
        map<int,vector<int>>m;

        for(int i=0;i<mat.size();i++){
            vector<int>temp = mat[i];

            for(int j=0;j<temp.size();j++){
                m[j].push_back(temp[j]);
            }
        }
        for(auto i:m){
            v.push_back(i.second);
        }
        int counter = 0;
        for(int i=0;i<mat.size();i++){
            int onecount = 0;
            int column = 0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1){
                    column = j;
                    onecount++;
                }
            }
            if(onecount==1){
                int countone = 0;
                vector<int>temp = v[column];
                for(auto i:temp){
                    if(i==1){
                        countone++;
                    }
                }
                if(countone==1){
                    counter++;
                }
            }
        }
        return counter;
    }
};