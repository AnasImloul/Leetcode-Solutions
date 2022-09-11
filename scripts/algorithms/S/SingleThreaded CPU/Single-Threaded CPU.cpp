// Runtime: 1039 ms (Top 46.64%) | Memory: 141.9 MB (Top 37.92%)
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        //we use priority queue to get the least processing time from the available server
        //implement a min heap

        //dp is double pair
        //sp is single pair
        using dp=pair<long int,pair<long int,long int >> ;
        using sp=pair<long int,long int>;
        priority_queue<sp,vector<sp>,greater<sp>> pq;
        int len=tasks.size();
        //we can rearrage the tasks but we can't get the index in the original array
        vector<dp> rearrange;
        for(long int i=0;i<len;i++)
        {
            rearrange.push_back({tasks[i][0],{tasks[i][1],i}});
        }

        //rearrange contains the same as tasks but with extra value "index" in its original array

        //sort in the ascending order of their enqueue time
        //if two tasks have same enqueue time it will sort the one which has the less processing time
        sort(rearrange.begin(),rearrange.end());
        long int i=0;
        long int finishTime=rearrange[0].first;
        long int k=tasks.size();

        vector<int> res;
        while(k)
        {
            while(i<len && finishTime>=rearrange[i].first)
            {
                //push the processing time and the index
                pq.push({rearrange[i].second.first,rearrange[i].second.second});
                i++;
            }

            //pick the task which is available upto the current finishTime and with the less processing time
            auto [time,ind]=pq.top();
            pq.pop();

            //processing the tasks take "time"
            finishTime+=time; //the cpu is now idle at the time finishTime
            res.push_back(ind);

            //now i points to the next task
            //if there are no tasks left in pq
            // and the next tasks enqueue time is larger than the current finishing time
            //we start with the task enqueue time
            if(pq.empty() && (i<len && finishTime < rearrange[i].first ))
                finishTime=rearrange[i].first;

            k--;
        }
        return res;

    }
};