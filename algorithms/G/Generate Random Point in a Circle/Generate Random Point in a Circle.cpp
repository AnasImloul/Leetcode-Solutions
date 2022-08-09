
class Solution {
public:
    double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double x_r = ((double)rand()/RAND_MAX * (2*r)) + (x-r);
        double y_r = ((double)rand()/RAND_MAX * (2*r)) + (y-r);
        
        while(solve(x_r,y_r,x,y)>=r*r)
        {
            x_r = ((double)rand()/RAND_MAX * (2*r)) + (x-r);
            y_r = ((double)rand()/RAND_MAX * (2*r)) + (y-r);
        }
        
        return {x_r,y_r};
    }
    
    double solve(double x_r,double y_r,double x,double y)
    {
        return (x-x_r)*(x-x_r) + (y-y_r)*(y-y_r);
    }
};
