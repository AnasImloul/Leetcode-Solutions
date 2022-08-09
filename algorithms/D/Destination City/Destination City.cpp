class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        string ans="";
        int flag=0;
        for(int i=0;i<paths.size();i++){
            for(int j=0;j<paths.size();j++){
                if(paths[i][1]==paths[j][0])
                    break;
                else{
                    
                    if(j==paths.size()-1){
                        ans+=paths[i][1];
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        return ans;
    }
};
