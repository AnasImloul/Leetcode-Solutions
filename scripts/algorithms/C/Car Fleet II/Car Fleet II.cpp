class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars)
    {
        int n = cars.size();
        vector<double> res(n,-1.0);
        stack<int> st;// for storing indices
        for(int i=n-1;i>=0;i--)
        {
    //traversing from back if someone has greater speed and ahead of lesser speed car it will always be ahead 
            while(!st.empty() && cars[st.top()][1]>= cars[i][1])
                st.pop();
            while(!st.empty()) // for lesser speed car ahead of greater spped car
            {
                double collision_time = (double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(collision_time <=res[st.top()] || res[st.top()] == -1)
                {
                    res[i] = collision_time;
                    break;
                }
                st.pop();
            }
            
            st.push(i);
        }
        return res;
    }
};