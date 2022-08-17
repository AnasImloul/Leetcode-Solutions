class Solution {
public:
    void find(set<pair<int,int>>&s,vector<int>v)
    {
        int x=v[0], y=v[1], r=v[2];
        
        for(int i=x-r;i<=x+r;i++)
            for(int j=y-r;j<=y+r;j++)
                if(sqrt((x-i)*(x-i) + (y-j)*(y-j)) <= r)      //checks if distance of point from center is les than or equal to radius
                    s.insert({i,j});
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>>s;     //used set to store valid points as it does not store same points again(if there are in different circles) 
        
        for(int i=0;i<circles.size();i++)
            find(s,circles[i]);
        return s.size();
    }
};
