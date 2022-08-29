// Runtime: 19 ms (Top 17.89%) | Memory: 5.9 MB (Top 24.93%)
class Solution {
public:
    int arrangeCoins(int n) {

         int count=0;
         while(n>0)
         {
             count++;
             n=n-count;
         }
         if(n==0) //all the coins are used to make complete rows so n if fully uitlized till 0
         {
             return count;
         }
         else if(n<0) //if the last row has not been created fully then n will go negative
         {
             return count-1;
         }
         return -1; //this will never get encountered

    }
};