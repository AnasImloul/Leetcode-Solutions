// Runtime: 392 ms (Top 5.27%) | Memory: 19.5 MB (Top 5.07%)
class Solution {
public:

    int get_max(vector<int>&arr , int s , int e ){
        int mx_val = *max_element(arr.begin() + s , arr.begin() + e + 1);
        return (e-s + 1 )* mx_val ;
    }

    int solve( vector<int>&arr , int idx , int k , vector<vector<int>>&dp){

        if(idx >= arr.size() ) return 0;

        if(dp[idx][k] != -1 )
            return dp[idx][k];

        int ans = 0;

        for(int i = 0 ; i<k ; ++i ){
            if((idx + i ) > arr.size() - 1)
                break;

            int val = get_max(arr , idx , idx + i ) + solve( arr , idx + i + 1 , k , dp );
            ans = max( ans , val );
        }
        return dp[idx][k] = ans ;

    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<vector<int>>dp(arr.size()+1 , vector<int>( k + 1 , -1 ));

        return solve( arr , 0 , k , dp );
    }
};