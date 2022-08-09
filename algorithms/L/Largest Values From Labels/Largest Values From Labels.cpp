class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        // same label item should be less than uselimit
        priority_queue<pair<int,int>>q;  // this will give us maximum element because we need to maximise the sum 
        for(int i=0;i<values.size();i++)
        {
            q.push({values[i],i});
        }
        long long int ans=0;
        unordered_map<int,int>m;
        // we cant use more numbers than useLimit
        // storing each use labels in map to count the use limit of that number
        int i=0;
        while(i<numWanted)
        {
            int t=q.top().first;   //number 
            int ind=q.top().second; // labels index
            q.pop();
            if(m[labels[ind]]<useLimit)   // if less than count then include in our answer
            {
                ans+=t;
                m[labels[ind]]++;
                i++;
            }
            if(q.size()==0)
            {
                break;
            }
        }
        return ans;
    }
};
