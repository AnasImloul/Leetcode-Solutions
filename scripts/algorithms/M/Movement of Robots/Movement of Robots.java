// Runtime: 10 ms (Top 98.51%) | Memory: 58.10 MB (Top 7.46%)

class Solution {
  public int sumDistance(int[] nums, String s, int d) {
    final int modulo = (int) 1e9 + 7;
    final int n = nums.length;
    long[] position = new long[n];
    for (int i = 0; i < n; i++) {
      position[i] = (s.charAt(i) == 'L' ? -1L : 1L) * d + nums[i];
    }

    Arrays.sort(position);
    long distance = 0;
    long prefix = 0;
    for (int i = 0; i < n; i++) {
      distance = (distance + (i * position[i] - prefix)) % modulo;
      prefix += position[i];
    }

    return (int) distance;
  }
}

