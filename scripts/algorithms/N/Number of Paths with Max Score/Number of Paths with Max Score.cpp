// Runtime: 111 ms (Top 23.90%) | Memory: 31.1 MB (Top 16.67%)
class Solution {
public:
    int mod=1e9+7;
    map<pair<int,int>,pair<int,int>>h;
    pair<int,int>solve(vector<string>&board,int i,int j,int n,int m)
    {
        //base case if you reach top left then 1 path hence return 1
        if(i==0 && j==0)return {0,1};
        //return 0 as no path is detected
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='X')return {INT_MIN,0};
        //check if it is stored or not
        if(h.find({i,j})!=h.end())return h[{i,j}];
        int no=0,cnt=0;
        if(board[i][j]!='S')no=board[i][j]-'0';
        //top ,left ,top left
        auto a=solve(board,i-1,j,n,m);
        auto b=solve(board,i,j-1,n,m);
        auto c=solve(board,i-1,j-1,n,m);
        //maxi ans
        int curr=(max(a.first,max(b.first,c.first)))%mod;
        //if maxi ans == a , b , c then increament count of a ,b,c
        if(curr==a.first)cnt+=a.second;
        if(curr==b.first)cnt+=b.second;
        if(curr==c.first)cnt+=c.second;
        return h[{i,j}]={(curr+no)%mod,cnt%mod};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        auto ans=solve(board,board.size()-1,board[0].size()-1,board.size(),board[0].size());
        if(ans.first<0)return {0,0};
        return {ans.first%mod,ans.second%mod};
    }
};