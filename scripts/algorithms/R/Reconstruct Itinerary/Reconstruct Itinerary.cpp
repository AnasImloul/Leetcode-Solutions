// Runtime: 91 ms (Top 9.61%) | Memory: 14.2 MB (Top 85.49%)
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> myMap;
        stack<string> myStack;
        vector<string> ans;
        for (int i=0; i<tickets.size(); ++i) {
            myMap[tickets[i][0]].insert(tickets[i][1]);
        }
        myStack.push({"JFK"});
        while (!myStack.empty()) {
            string top = myStack.top();
            if (!myMap[top].empty()) {
                myStack.push(*myMap[top].begin());
                myMap[top].erase(myMap[top].begin());
            } else {
                ans.insert(ans.begin(), top);
                myStack.pop();
            }
        }
        return ans;
    }
};
// Time : O(E)
// Space : O(V + E)