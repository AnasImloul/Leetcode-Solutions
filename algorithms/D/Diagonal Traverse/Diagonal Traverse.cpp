class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int>vec;
        int m=mat.size()-1,n=mat[0].size()-1;
        int i=0,j=0;
        if(m==-1){
            return {};
        }
        if(m==0){
            for(int i{0};i<=n;++i){
                vec.push_back(mat.at(0).at(i));
            }
            return vec;
        }else if(n==0){
            for(int i{0};i<=m;++i){
                vec.push_back(mat.at(i).at(0));
            }
            return vec;
        }
        for(int k{0};k<=m+n;k++){
            if(k==0){
                vec.push_back(mat.at(0).at(0));
                j++;
            }else if(k==m+n){
                vec.push_back(mat.at(m).at(n));
            }else if(k%2!=0){
                while(i<=m && j>=0 && j<=n){
                    vec.push_back(mat.at(i).at(j));
                    i++;
                    j--;
                }
                if(i<=m && j<0){
                    j++;
                }else if(i>m &&j>=0){
                    j+=2;
                    i--;
                }else if(i>m && j<0){
                    i--;
                    j+=2;
                }
                
            }else{
                
                while(i>=0 && j<=n){
                    vec.push_back(mat.at(i).at(j));
                    i--;
                    j++;
                }
                if(i<0 &&j<=n){
                    i++;    
                }else if(i<0 && j>n){
                    i+=2;
                    j--;
                }else if(i>m && j<0){
                    i--;
                    j+=2;
                }else if(i>=0 && j>n){
                    i+=2;
                    j--;
                }
            }
        }
        return vec;
    }
};
