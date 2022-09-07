// Runtime: 0 ms (Top 100.00%) | Memory: 6.1 MB (Top 26.58%)
class Solution {
public:
    int subtractProductAndSum(int n) {
        vector<int> digit;
        int product=1;
        int sum=0;
        while(n>0){
            digit.push_back(n%10);
            n/=10;
        }
        for(int i=0;i<digit.size();i++){
            product*=digit[i];
            sum+=digit[i];
        }
        return product-sum;

    }
};