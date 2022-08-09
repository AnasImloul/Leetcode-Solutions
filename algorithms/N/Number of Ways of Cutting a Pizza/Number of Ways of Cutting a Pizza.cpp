class Solution {
private:
    int mod=1000000000+7;
    vector<vector<vector<int>>>mem;
    vector<vector<bool>>colContainsApple,rowContainsApple;
    int solve(vector<string>&pizza,int r,int c,int cuts){
        int m=pizza.size(),n=pizza[0].size();
        if(cuts==0){
            for(int row=r;row<m;row++){
                if(rowContainsApple[row][c]){
                    return 1;
                }
            }
            for(int col=c;col<n;col++){
                if(colContainsApple[r][col]){
                    return 1;
                }
            }
            return 0;
        } else if(mem[r][c][cuts]!=-1){
            return mem[r][c][cuts];
        } else {
            int ans=0;
            bool present=false;
            for(int row=r;row<=m-2;row++){
                if(!present and rowContainsApple[row][c]){
                    present=true;
                }
                if(present){
                    ans=(ans%mod+solve(pizza,row+1,c,cuts-1)%mod)%mod;
                }
            }
            present=false;
            for(int col=c;col<=n-2;col++){
                if(!present and colContainsApple[r][col]){
                    present=true;
                }
                if(present){
                    ans=(ans%mod+solve(pizza,r,col+1,cuts-1)%mod)%mod;
                }
            }
            return mem[r][c][cuts]=ans;
        }
    }
public:
    int ways(vector<string>& pizza, int k) {
        int m=pizza.size(),n=pizza[0].size();
        mem=vector<vector<vector<int>>>(m,vector<vector<int>>(n,vector<int>(k,-1)));
        colContainsApple=vector<vector<bool>>(m,vector<bool>(n,false));
        rowContainsApple=vector<vector<bool>>(m,vector<bool>(n,false));
        for(int col=0;col<n;col++){
            for(int row=m-1;row>=0;row--){
                if(pizza[row][col]=='A' or (row!=m-1 and colContainsApple[row+1][col])){
                    colContainsApple[row][col]=true;
                }
            }
        }
        for(int row=0;row<m;row++){
            for(int col=n-1;col>=0;col--){
                if(pizza[row][col]=='A' or (col!=n-1 and rowContainsApple[row][col+1])){
                    rowContainsApple[row][col]=true;
                }
            }
        }
        return solve(pizza,0,0,k-1);
    }
};