class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p{p1, p2, p3, p4};
        unsigned short ans{0};
        double scal;
        vector<double> bar(2);
        /* compute the barycenter */ 
        bar[0] = (p1[0] + p2[0] + p3[0] + p4[0]) / 4.;
        bar[1] = (p1[1] + p2[1] + p3[1] + p4[1]) / 4.;
        const double length = pow(p1[0]-bar[0],2) + pow(p1[1] - bar[1],2);
        for (size_t i=0; i<4; i++) {if ((pow(p[i][0]-bar[0], 2) + pow(p[i][1] - bar[1], 2)) != length) return false; 
            for (size_t j=i+1; j<4;j++){
                scal = (bar[0] - p[i][0])*(bar[0] - p[j][0]) + (bar[1] - p[i][1])*(bar[1]- p[j][1]);
                ans += (scal==0.)?1:0;}}
        return  ans==4;
    }
};