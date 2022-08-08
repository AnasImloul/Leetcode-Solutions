class Solution {
public:
    bool check(int n){
        vector<bool> isif(10);
        for(int i = 1; i <= 9; i++){
            if(n % i == 0) isif[i] = 1;
        }
        
        while(n > 0){
            if(isif[n%10] == 0) return false;
            n /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i = left; i <= right; i++){
            if(check(i)) ans.push_back(i);
        }
        return ans;
    }
};
