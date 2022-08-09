class Solution {
public:
    bool check(int x , int y , int u , int v ,int n , vector<vector<int>>& pref){
        int id_x = 0 , id_y = 0 , id_u = 0  , id_v = 0 ;
        //check indices of (y and u) in pref[x] ;
        for(int i = 0 ; i < n - 1; ++i ){
            if(pref[x][i] == y) id_y = i ;
            if(pref[x][i] == u) id_u = i ;
        }
        
        //check indices of (v and x) in pref[u] ;
        for(int i = 0 ; i < n - 1 ; ++i ){
            if(pref[u][i] == v) id_v = i ;
            if(pref[u][i] == x) id_x = i ;
        }
        
        return (id_x < id_v and id_u < id_y) ;
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        unordered_set<int> unhappy ;
        for(int i = 0 ; i < pairs.size() ; ++i ){
            for(int j = i + 1; j < pairs.size() ; ++j){
                int x = pairs[i][0] , y = pairs[i][1] , u = pairs[j][0] , v = pairs[j][1] ;
                // x prefers u over y and u preferes x over v 
                if(check(x,y,u,v,n,preferences)) unhappy.insert(x), unhappy.insert(u) ;
                // x prefers v over y and v prefers x over u 
                if(check(x,y,v,u,n,preferences)) unhappy.insert(x) , unhappy.insert(v) ;
                // y prefers u over x and u prefers y over v
                if(check(y,x,u,v,n,preferences)) unhappy.insert(y) , unhappy.insert(u) ;
                // y prefers v over x and v prefers y over u 
                if(check(y,x,v,u,n,preferences)) unhappy.insert(y) , unhappy.insert(v) ;
            }
        }
        return unhappy.size() ;
    }
};
