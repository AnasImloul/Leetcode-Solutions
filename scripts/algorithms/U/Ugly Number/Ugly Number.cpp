// Runtime: 3 ms (Top 59.11%) | Memory: 5.7 MB (Top 87.39%)
class Solution {
public:
   bool isUgly(int n)
  {
     if (n <= 0) return false;
     int n1 = 0;
     while(n != n1)
     {
     n1 = n;
     if ((n % 2) == 0) n /= 2;
     if ((n % 3) == 0) n /= 3;
     if ((n % 5) == 0) n /= 5;
     }
     if (n < 7) return true;
     return false;
  }
};