class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqsg;
        priority_queue<pair<int, int>> pqgs;
        int n = capital.size();
        for(int i = 0; i < n; i++)
        {
            //int val = profit[i]-capital[i];
            if(capital[i] <= w)
            {
                pqgs.push({profits[i],capital[i]});
            }
            else if(capital[i] > w)
            {
                pqsg.push({capital[i],profits[i]});
            }
        }
        while(k-- && !pqgs.empty())
        {
            pair<int, int> tmp = pqgs.top();
            w += tmp.first;
            pqgs.pop();
            while(!pqsg.empty() && pqsg.top().first <= w)
            {
                pqgs.push({pqsg.top().second,pqsg.top().first});
                pqsg.pop();
            }
        }
        return w;
    }
};
