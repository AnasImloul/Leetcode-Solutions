class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int sum = 0,cnt=0,temp=0;
        for(int i=0;i<n;i++){
            
            int x = nums[i];
            int sq = sqrt(x);
            
            for(int j=1;j<=sq;j++){
                if(x%j==0){
                    cnt+=2; temp += (j+x/j);
                    
                    if(j==x/j){
                        cnt--; temp-=j;
                    }
                    
                    if(cnt>4)
                        break;
                }
            }
            if(cnt==4){
                sum += temp;
            }
            temp=0; cnt=0;
        }
        return sum;
    }
};
