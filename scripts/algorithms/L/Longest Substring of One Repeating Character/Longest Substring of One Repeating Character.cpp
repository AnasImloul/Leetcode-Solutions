// Runtime: 1433 ms (Top 23.41%) | Memory: 179.2 MB (Top 26.07%)
class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        multiset<int> ls; // ordered set of lengths of all intervals at present
        set<int> ins; // ordered set representing the left-ends of intervals
        int n = s.length();
        ins.insert(n); // allow us to get length of current interval by *next(it) - *it for all cases

        // initialize the ordered sets with the original string
        for (int i = 0, j = 1; i < n;) {
            while (j < n && s[j] == s[j-1]) ++j;
            ins.insert(i);
            ls.insert(j-i);
            i = j++;
        }

        // update the string and track the length of the longest substring
        // by merging/splitting intervals
        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); ++i) {
            // If the querying character does not change the string:
            // do nothing for the sets
            if (queryCharacters[i] == s[queryIndices[i]]) {
                ans.push_back(*ls.rbegin());
                continue;
            }

            // update the ordered sets
            // 1. split the involved interval to parts: (left), self, (right)
            // ins = 0 3 6
            // s = b b b c c c
            // query : b
            // => ins = 0 3 4 6
            // => s = b b b b c c

            // find the left-end of the target interval
            auto it = prev(ins.upper_bound(queryIndices[i])); // old/left interval
            int oldl = *next(it) - *it; // old interval length
            ls.erase(ls.find(oldl));

            ins.insert(queryIndices[i]); // self interval
            ins.insert(queryIndices[i] + 1); // right interval
            if (*it != queryIndices[i]) ls.insert(queryIndices[i] - *it); // left interval length
            ls.insert(1); // self interval length
            if (oldl - (queryIndices[i] - *it + 1)) ls.insert(oldl - (queryIndices[i] - *it + 1) ); //right interval length

            s[queryIndices[i]] = queryCharacters[i];

            // 2. merge the adjacent intervals if the characters are identical
            // ins = 0 3 4 6
            // s = b b b b c c
            // => ins = 0 4 6

            it = ins.find(queryIndices[i]); // self interval
            // merge self and right
            if (queryIndices[i] + 1 < n && s[queryIndices[i]] == s[queryIndices[i] + 1]) {
                ls.erase(ls.find(*next(it, 2) - *next(it)));
                ls.erase(ls.find(1));
                ins.erase(next(it));
                ls.insert(*next(it) - *it);
            }
            // merge left and self
            if (it != ins.begin() && s[queryIndices[i]] == s[queryIndices[i] - 1]) {
                ls.erase(ls.find(*next(it) - *it) );
                ls.erase(ls.find(*it - *prev(it)) );
                ls.insert(*next(it) - *prev(it));
                ins.erase(it);
            }
            ans.push_back(*ls.rbegin());

        }
        return ans;
    }
};