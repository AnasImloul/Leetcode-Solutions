// Runtime: 5 ms (Top 35.84%) | Memory: 7 MB (Top 15.75%)
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> v;
        for(int i=0;i<s.size();i=i+k)
        {
            string t=s.substr(i,k); // make substring of size atmost k

            if(t.size()==k) // if size if k then push
            {
                v.push_back(t);
                continue;
            }

            int l=t.size(); // if it is the last group and size if less than k
            for(int j=0;j<(k-l);j++) // add fill char to t to make size k
                t+=fill;

            v.push_back(t);
        }
        return v;
    }
};