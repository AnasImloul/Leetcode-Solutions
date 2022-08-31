// Runtime: 207 ms (Top 46.27%) | Memory: 117.2 MB (Top 26.87%)
class Solution {
    public int nextBeautifulNumber(int n) {

        while(true){
            n++;
           int num = n; //test this number
           int [] freq = new int[10]; // 0 to 9

            while(num > 0){ //calculate freq of each digit in the num
                int rem = num % 10; //this is remainder
                num = num / 10; //this is quotient
                freq[rem] = freq[rem] + 1; //increase its frequency
                if(freq[rem] > rem) break;
            }

            boolean ans = true;

            for(int i = 0;i<10;i++){ //check frequency of each digit
              if(freq[i] != i && freq[i] != 0){
                  ans = false;
                  break;
              }
            }

            if(ans == true){
                return n;
            }
        }
    }
}