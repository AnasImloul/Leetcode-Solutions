class Solution {

        public int[] constructDistancedSequence(int n) {
            int[] ans = new int[n * 2 - 1];
            boolean[] visited = new boolean[n + 1];
            calc(0, ans, visited, n);
            return ans;
        }

        private boolean calc(int index, int[] ans, boolean[] visited, int n) {
            if (index == ans.length) {
                return true;
            }
            if (ans[index] != 0) return calc(index + 1, ans, visited, n); // value already assigned in this position. So go ahead with the next index.
            else {
				// we start from n to 1 since we need to find out the lexicographically largest sequence.
                for (int i = n; i >= 1; i--) {
                    if (visited[i]) continue;
                    visited[i] = true;
                    ans[index] = i;
                    if (i == 1) {
                        if (calc(index + 1, ans, visited, n)) return true;
                    } else if (index + i < ans.length && ans[index + i] == 0) {
                        ans[i + index] = i; // assigning the second occurence of i in the desired position i.e, (current index + i )
                        if (calc(index + 1, ans, visited, n)) return true; // largest possible sequence satisfying the given conditions found.
                        ans[index + i] = 0;
                    }
                    ans[index] = 0;
                    visited[i] = false;
                }

            }
            return false;
        }
    }
	
