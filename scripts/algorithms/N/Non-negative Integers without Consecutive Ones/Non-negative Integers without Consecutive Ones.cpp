class Solution {
public:
    int dp[31][2];
    vector<int> f(){ 
        vector<int> res(31, 1);
        dp[1][0]=0;
        dp[1][1]=1;
        for(int i=2; i<31; i++){
            dp[i][0]=dp[i-1][0]+dp[i-1][1];
            dp[i][1]=dp[i-1][0];
        }
        
        
        for(int i=1; i<31; i++){
            res[i]=res[i-1]+dp[i][0]+dp[i][1];
        }

        res[1]=2;
        return res;
    }
    
    int findIntegers(int n) {
        int res=0;
        int bits=0;
        int temp=n;
        vector<int> v;
        while(temp>0){
            bits++;
            v.push_back(temp&1);
            temp=temp>>1;
        }
        vector<int> nums=f();
        
        bool valid=true, isValid=true;

        for(int i=bits-2;i>=0;i--){
            if(v[i]==1 && v[i+1]==1){
                res+=nums[i];
                isValid=false;
                break;
            }else if(v[i]==1)
                res+=nums[i];
        }
        
        res+=nums[bits-1];
        return isValid==true ? res+1:res;
    }
};


