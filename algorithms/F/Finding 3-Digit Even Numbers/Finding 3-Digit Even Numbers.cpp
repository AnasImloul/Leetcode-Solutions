class Solution {
 public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    // generating frequency map of the given digits
    vector<int> count(10, 0);
    for (auto& d : digits) count[d]++;

    vector<int> res;

    for (int num = 100; num < 999; num += 2) {
      // generating frequency map of the current number
      vector<int> currCount(10, 0);
      int temp = num;

      while (temp) {
        currCount[temp % 10]++;
        temp /= 10;
      }

      // checking if the number can be generated or not
      bool flag = true;
      for (int i = 0; i < 10; i++) {
        if (currCount[i] > count[i]) {
          flag = false;
          break;
        }
      }

      if (flag) {
        res.push_back(num);
      }
    }
    return res;
  }
};
