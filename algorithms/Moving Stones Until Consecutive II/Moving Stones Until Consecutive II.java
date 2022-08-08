	class Solution {
		public int[] numMovesStonesII(int[] stones) {
			int n = stones.length;
			 int[] ans = new int[2];
			 int i = 0, j = 0, wsize, scount, minMoves = Integer.MAX_VALUE;
			Arrays.sort(stones);
			 while (j < n) {
				wsize = stones[j] - stones[i] + 1;
				scount = j - i + 1;

				if (wsize > n) {
					i++;
					continue;
				}

				if (wsize == n - 1 && scount == n - 1)
					minMoves = Math.min(minMoves, 2);

				else minMoves = Math.min(minMoves, n - scount);

				j++;
			}
			ans[0] = minMoves;
			int maxMoves = 0;
			 if (stones[1] == stones[0] + 1 || stones[n - 1] == stones[n - 2] + 1)
				maxMoves = stones[n - 1] - stones[0] + 1 - n;
			else 
				maxMoves = Math.max(((stones[n - 1] - stones[1]) - (n - 1) + 1), ((stones[n - 2] - stones[0]) - (n - 1) + 1));

			ans[1] = maxMoves;
			return ans;
		}
	}