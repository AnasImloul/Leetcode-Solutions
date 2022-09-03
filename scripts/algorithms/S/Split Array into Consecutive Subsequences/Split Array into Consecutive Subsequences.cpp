// Runtime: 581 ms (Top 5.01%) | Memory: 70.7 MB (Top 7.44%)
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> um;
        for(int &num : nums)
        {
            pq.push(num);
            um[num]++;
        }
        queue<int> q;
        int count = 0, prev;
        while(!pq.empty())
        {
            if(count == 0)
            {
                prev = pq.top();
                pq.pop();
                count++;
            }
            else if(pq.top() == prev+1)
            {
                if(um[pq.top()] >= um[prev])
                {
                    um[prev]--;
                    pq.pop();
                    prev += 1;
                    count++;
                }
                else if(um[pq.top()] < um[prev])
                {
                    um[prev]--;
                    if(count <= 2) return false;
                    while(!q.empty())
                    {
                        pq.push(q.front());
                        q.pop();
                    }
                    count = 0;
                }
            }
            else if(pq.top() == prev)
            {
                q.push(pq.top());
                pq.pop();
                if(pq.empty())
                {
                    if(count <= 2) return false;
                    while(!q.empty())
                    {
                        pq.push(q.front());
                        q.pop();
                    }
                    count = 0;
                }
            }
            else if(pq.top() > prev+1)
            {
                if(count <= 2) return false;

                while(!q.empty())
                {
                    pq.push(q.front());
                    q.pop();
                }
                count = 0;
            }
        }
        if(count > 0 && count <= 2) return false;
        return true;
    }
};