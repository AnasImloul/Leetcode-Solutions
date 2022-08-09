class Solution {
    int eval(int a, int b, char op) {
        if (op == '+') {
            return a + b;
        } else {
            return a * b;
        }
    }
    
    unordered_map<string_view, unordered_set<int>> mp;
    unordered_set<int> potential;
    
    unordered_set<int>& solve(string_view s) {
        if (auto it = mp.find(s); it != mp.end()) {
            return it->second;
        }
        
        bool res = true;
        int n = 0;
        unordered_set<int> ans;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            } else {
                n = 0;
                res = false;
                for (int l : solve(s.substr(0, i))) {
                    for (int r : solve(s.substr(i + 1))) {
                        int res2 = eval(l, r, c);
                        if (res2 <= 1000) {
                            ans.insert(res2);
                        }
                    }
                }
            }
        }
        if (res) {
            ans.insert(n);
        }
        return mp[s] = ans;
    }
    
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        int ans = 0, correct = 0;
        stack<int> ns, op;
        unordered_map<char, int> prec{
            {'+', 1},
            {'*', 2},
            {'(', 0}
        };
        int n = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                n = n * 10 + (c - '0');
            } else if (c == '(') {
                op.push(c);
            } else if (c == ')') {
                ns.push(n);
                while (op.top() != '(') {
                    int b = ns.top();
                    ns.pop();
                    int a = ns.top();
                    ns.pop();
                    ns.push(eval(a, b, op.top()));
                    op.pop();
                }
                op.pop();
                n = ns.top();
                ns.pop();
            } else {
                ns.push(n);
                n = 0;
                int p = prec[c];
                while (!op.empty() && prec[op.top()] >= p) {
                    int b = ns.top();
                    ns.pop();
                    int a = ns.top();
                    ns.pop();
                    ns.push(eval(a, b, op.top()));
                    op.pop();
                }
                op.push(c);
            }
        }
        ns.push(n);
        while (!op.empty()) {
            int b = ns.top();
            ns.pop();
            int a = ns.top();
            ns.pop();
            ns.push(eval(a, b, op.top()));
            op.pop();
        }
        correct = ns.top();
        
        string_view sv{s.data(), s.size()};
        solve(sv);
        for (int n2 : mp[sv]) {
            potential.insert(n2);
        }
        
        for (int n2 : answers) {
            if (n2 == correct) {
                ans += 5;
            } else if (potential.find(n2) != potential.end()) {
                ans += 2;
            }
        }
        return ans;
    }
};
