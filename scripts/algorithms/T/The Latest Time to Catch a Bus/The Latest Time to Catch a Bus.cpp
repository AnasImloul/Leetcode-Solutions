class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        queue<int> q;
        sort(buses.begin(),buses.end());
        sort(passengers.begin(),passengers.end());
        int n=buses.size();
        int m=passengers.size();
        set<int> st;
        for(auto p:passengers)
        {
            q.push(p);
            st.insert(p);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int currbus=buses[i]; // curr bus depature time.
            int count=0; //number of people in curr bus
            int x;
            //CASE1
            while(!q.empty() && count<capacity && q.front()<=currbus)
            {
                x=q.front();
                q.pop();
                if(st.find(x-1)==st.end()) //checking if person timing-1 doesnt exist and update the answer.
                    ans=x-1; 
                count++;
            }
            //CASE2
            if(count<capacity)
            {
                while(st.find(currbus)!=st.end()) //starting from dept time find a time which does not exist int the set already.
                {
                    currbus--;
                }
                ans=max(ans,currbus);
            }
            
        }
        return ans;
    }
};
