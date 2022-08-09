class Solution {
    public int countNumbersWithUniqueDigits(int n) {
        // Logic --> 
        /*
        if n == 0 --> the number is upto 10^0 --> 1 and 1 possibilites could be there
        if n == 1 --> the range is upto 10^1 --> 10(10 unique combinations from 1 to 10 can be there)
        so the bases cases are --> n == 0 and n == 1
        
        
        Suppose the case of n = 3
        The upper limit is 10^3 --> 1000. So, _ _ _ be filled in following ways -->
        _ (9 choices except 0) _ (9 choices except the one filled in previous blank but 0 can be included) _ (8 choices). So for 3 digit, 9*9*8 + 9*9 choices for 2 digits+9(for 1 digit) + 1(0 digits)...
        
        */
        int ans = 10;
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return ans;
        }
        int counter = 9;
        int choiceFiller = 9;
        while(n --> 1 && choiceFiller>0){
            counter *= choiceFiller--;
            ans += counter;
        }
        return ans;
    }
}
