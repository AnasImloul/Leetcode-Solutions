// Runtime: 5 ms (Top 46.5%) | Memory: 6.40 MB (Top 33.1%)

class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int>temp;

        for(int i=1;i<=n;i++) temp.push_back(i);

        int i=0;

        while(temp.size()>1){
            int t=temp.size();
            i=(i+k-1)%t;
            temp.erase(temp.begin()+i);
        }
        return *temp.begin();
    }
};