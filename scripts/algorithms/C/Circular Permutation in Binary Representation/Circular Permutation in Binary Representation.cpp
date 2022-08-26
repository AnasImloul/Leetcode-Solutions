// Runtime: 280 ms (Top 7.77%) | Memory: 78.8 MB (Top 5.30%)
class Solution {
public:
    vector<string> get_val(int n)
    {
        if(n==1)return {"0","1"};
        vector<string> v = get_val(n-1);
        vector<string> ans;
        for(int i = 0;i<v.size();i++)
        {
            ans.push_back("0" + v[i]);
        }

        for(int i = v.size()-1;i>=0;i--)
        {
            ans.push_back("1" + v[i]);
        }
        return ans;
    }

    vector<int> solve(int n)
    {
        vector<string> v = get_val(n);
        vector<int> ans;
        for(int i = 0;i<v.size();i++)
        {
            string s = v[i];
            int x = 0;
            for(int j = 0;j<s.size();j++)
            {
                x = x*2 + s[j]-'0';
            }
            ans.push_back(x);
        }
        return ans;
    }

    vector<int> circularPermutation(int n, int start) {

        vector<int> v = solve(n);
        int ind;
        for(int i = 0;i<v.size();i++)
        {
            if(v[i]==start)
            {
                ind = i;
                break;
            }
        }

        vector<int> ans;
        for(int i = ind;i<v.size();i++)
        {
            ans.push_back(v[i]);
        }
        for(int i = 0;i<ind;i++)
        {
            ans.push_back(v[i]);
        }
        return ans;
    }
};