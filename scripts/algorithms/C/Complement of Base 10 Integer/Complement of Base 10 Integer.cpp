// Runtime: 3 ms (Top 37.98%) | Memory: 5.9 MB (Top 76.79%)

class Solution {
public:
  int bitwiseComplement(int n) {

    //-------Exceptional Case---------------
    if(n == 0){
      return 1;
    }

    //-------Normal Case--------------------
    int testNumber = n;
    int rightShift = 0; // count of length on number in binary 5 == 101 => 3

    // counting
    while(testNumber != 0){
      testNumber = testNumber >> 1;
      rightShift++;
    }

    // generating mask
    int mask = 0;
    while(rightShift != 0){
      mask = mask << 1;
      mask = mask | 1;
      rightShift--;
    }

    // complementing
    int temp = ~n;
    int result = temp & mask;
    return result;
  }
};