// Runtime: 81 ms (Top 78.44%) | Memory: 41.8 MB (Top 95.21%)

/*

Using DFS and Memo :

1. We will start from start pos provided and will dfs travel to each other location .
2. each time we will see if we reach finish , we will increment the result . but we wont stop there if we have fuel left and continue travelling
3. if fuel goes negetive , we will return 0 , as there is no valid solution in that path
4. we will take dp[locations][fuel+1] to cache the result , to avoid recomputing .

*/

class Solution {

    int mod = (int)Math.pow(10,9) + 7 ;
    int[][] dp ;

    public int countRoutes(int[] locations, int start, int finish, int fuel) {

        dp = new int[locations.length][fuel+1] ;

        for(int[] row : dp){
            Arrays.fill(row , -1) ;
        }

        return dfs(locations , start , finish , fuel);
    }

    public int dfs(int[] locations , int cur_location , int finish , int fuel){

        if(fuel < 0){
            return 0 ;
        }

        if(dp[cur_location][fuel] != -1){
            return dp[cur_location][fuel] ;
        }

        int result = 0 ;

        if(cur_location == finish){
            result++ ;
        }

        for(int i=0 ; i<locations.length ; i++){

            if(i == cur_location) continue ;

            int fuel_cost = Math.abs(locations[i] - locations[cur_location]);
            int next_trip = dfs(locations , i , finish , fuel-fuel_cost);
            result += next_trip ;
            result %= mod ;
        }

        dp[cur_location][fuel] = result ;

        return dp[cur_location][fuel] ;
    }
}
