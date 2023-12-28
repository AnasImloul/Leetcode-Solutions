// Runtime: 0 ms (Top 100.0%) | Memory: 6.50 MB (Top 94.31%)

class Solution {
public:
    int sumDigits(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
    
    int getLucky(string s, int k) {
        int sum = 0;
        for(char &ch : s) {
		    int val = ch-'a'+1;
		    sum += val < 10 ? val : (val%10 + val/10);
		}

        k -= 1; //Why ? We already did one transformation above (getting sum of character values)
        while(k-- && sum >= 10) //sum >= 10 reduces unwanted Transform calls because if we are left with 1-digit,that will be our result
            sum = sumDigits(sum);
        
        return sum;
    }
};
