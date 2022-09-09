// Runtime: 0 ms (Top 100.00%) | Memory: 7.2 MB (Top 42.17%)
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double sum = 0;
        for(int i = 1; i < salary.size()-1; i++)
        {
            sum += salary[i];
        }

        return sum/(salary.size()-2);
    }
};