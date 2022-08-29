// Runtime: 324 ms (Top 61.68%) | Memory: 88.2 MB (Top 5.31%)
class StockSpanner {
public:
    stack<pair<int , int>>s; //val , index
    vector<int>prices;
    vector<int>res;
    StockSpanner() {

    }

    int next(int price) {
        prices.push_back(price);
        int n = prices.size();
        for(int i = n-1 ; i<n ; i++)
        {
            while(!s.empty() and s.top().first <= prices[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                res.push_back(i - 0 + 1);
                s.push({prices[i] , i});
            }
            else
            {
                auto it = s.top();
                res.push_back({i - it.second });
                s.push({prices[i] , i});
            }
        }
        return res[n-1];
    }
};