class Solution {
public:
    int get_ternary_mask_bit(int mask,int i){
        mask/=(int)pow(3,i);
        return mask%3;
    }
    int get_next_mask(int mask,int val,int n){
        return (mask*3+val)%(243);
    }
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        // --> index introvert_left extrovert_left introvert_mask extrovert_mask
        // 0 -> empty
        // 1 -> introvert
        // 2 -> extrovert
        vector<vector<vector<vector<int>>>> dp(26,vector<vector<vector<int>>>(7,vector<vector<int>>(7,vector<int>(244,INT_MIN))));
        if(m>n)swap(m,n);
        if(m==1&&n==1){
            if(introvertsCount)return 120;
            else if(extrovertsCount)return 40;
            else return 0;
        }
        map<pair<int,int>,int> score_map_intro = {{{0,0},120},{{0,1},120-30-30},{{0,2},120+20-30},{{1,1},120-30-30-30-30},{{1,2},120-30-30-30+20},{{2,2},120-30-30+20+20}};
        map<pair<int,int>,int> score_map_extro = {{{0,0},40},{{0,1},40-30+20},{{0,2},40+20+20},{{1,1},40+20+20-30-30},{{1,2},40+20+20+20-30},{{2,2},40+20+20+20+20}};
        int ans = 0;
        for(int a=0;a<m*n;a++){
          for(int b=introvertsCount;b>=0;b--){
              for(int c=extrovertsCount;c>=0;c--){
                  for(int mask=0;mask<pow(3,5);mask++){
                         int i = a/n;
                         int j = a%n;
                         int up_bit   = i>0?(get_ternary_mask_bit(mask,n-1)):(0);
                         int left_bit = j>0?(get_ternary_mask_bit(mask,0)):(0);
                         if(a==0)dp[a][b][c][mask]=0;
                         if(left_bit>up_bit)swap(left_bit,up_bit);
                         // case 1 making this cell empty
                         dp[a+1][b][c][get_next_mask(mask,0,n)]=max(dp[a+1][b][c][get_next_mask(mask,0,n)],dp[a][b][c][mask]);
                         // case 2 making this cell introvert
                         if(b>0)
                         dp[a+1][b-1][c][get_next_mask(mask,1,n)]=max(dp[a+1][b-1][c][get_next_mask(mask,1,n)],dp[a][b][c][mask]+score_map_intro[{left_bit,up_bit}]);
                         // case 3 making this cell extrovert
                         if(c>0)
                         dp[a+1][b][c-1][get_next_mask(mask,2,n)]=max( dp[a+1][b][c-1][get_next_mask(mask,2,n)],dp[a][b][c][mask]+score_map_extro[{left_bit,up_bit}]);
                  }
              }
          }
        }
        for(int b=introvertsCount;b>=0;b--)for(int c=extrovertsCount;c>=0;c--)for(int mask=0;mask<pow(3,5);mask++)ans=max(ans,dp[n*m][b][c][mask]);

        return ans;
    }
};