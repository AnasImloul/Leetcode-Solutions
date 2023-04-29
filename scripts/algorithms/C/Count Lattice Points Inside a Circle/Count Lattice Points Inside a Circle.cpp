class Solution {
public:
    bool circle(int x , int y , int c1 , int c2, int r){
        if((x-c1)*(x-c1) + (y-c2)*(y-c2) <= r*r) 
            return true ;
        return false ;
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
        int n = circles.size() , ans = 0 ;
        set<pair<int,int>> set ;
        for(auto v : circles){
            int r = v[2] , x = v[0] , y = v[1]; 
            for(int i = x-r ; i <= x+r ; i++)
                for(int j = y-r ; j <= y+r ; j++)
                    if(circle(i,j,x,y,r)){
                        pair<int,int> p(i,j) ;
                        set.insert(p) ;
                    }
        }
        return set.size() ;
    }
};