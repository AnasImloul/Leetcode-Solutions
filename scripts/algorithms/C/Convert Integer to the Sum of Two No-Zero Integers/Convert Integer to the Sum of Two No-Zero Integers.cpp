class Solution {
public:
    int has0(int x)
{
    while (x){
        if (x % 10 == 0)
          return 1;
        x /= 10;
    } 
    return 0;
}
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<=n;i++){
            if(has0(i)==false && has0(n-i)==false){
                return {i,n-i};
            }
        }
        return {1,1};
    }
};
