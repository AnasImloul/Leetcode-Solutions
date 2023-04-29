class Solution {
private:
    int countones( int n ){
        int count = 0;
        while(n){
            count ++;
            n = n & ( n-1 );
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for( int i = 0; i <= n; i++ ){
            int x = countones(i);
            ans.push_back(x);
        }
        return ans;
    }
};