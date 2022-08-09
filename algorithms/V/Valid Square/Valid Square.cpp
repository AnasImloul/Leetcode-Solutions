class Solution {
public:
    int dis(vector<int>& p, vector<int>& q){
        return pow(p[0]-q[0], 2) + pow(p[1]-q[1], 2);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<int> a;
        a.push_back( dis(p1, p2));   // all distance and sort them
        a.push_back( dis(p1, p3));   // if it is a valid square then last distance must be dianogal
        a.push_back( dis(p1, p4));
        a.push_back( dis(p3, p2));
        a.push_back( dis(p4, p2));
        a.push_back( dis(p4, p3));
        
        sort(a.begin(), a.end());
        if(a[0]>0 and a[0]==a[1] and a[1]==a[2] and a[2]==a[3] and a[4]==a[5] and 2*a[2]==a[4] ) return 1;
        return 0;
        
    }
};
