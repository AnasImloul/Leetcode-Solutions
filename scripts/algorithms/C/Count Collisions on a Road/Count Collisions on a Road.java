// Runtime: 22 ms (Top 59.94%) | Memory: 54.1 MB (Top 76.37%)
/*
cars on left side which are moving in left direction are never going to collide,
Similarly, cars on right side which are moving right side are never going to collide.

In between them every car is going to collide.
*/

class Solution {
    public int countCollisions(String directions) {
        int left = 0, right = directions.length() - 1;

        while (left < directions.length() && directions.charAt(left) == 'L') {
            left++;
        }

        while (right >= 0 && directions.charAt(right) == 'R') {
            right--;
        }

        int count = 0;
        for (int i = left; i <= right; i++) {
            if (directions.charAt(i) != 'S') {
                count++;
            }
        }
        //combining these three loops - TC : O(N).

        return count;
    }
}