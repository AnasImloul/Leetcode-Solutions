class Solution {
	public int minOperations(int[] target, int[] arr) {
		int n = target.length;
		Map<Integer, Integer> map = new HashMap<>();

		for(int i = 0; i < n; i++) {
			map.put(target[i], i);
		}

		List<Integer> array = new ArrayList<>();

		for(int i = 0; i < arr.length; i++) {
			if(!map.containsKey(arr[i])) {
				continue;
			}

			array.add(map.get(arr[i]));
		}

		int maxLen = 0;
		int[] tails = new int[n + 1];

		for(int i = 0; i < n; i++) {
			tails[i] = -1;
		}

		for(int num: array) {
			int index = findMinIndex(tails, maxLen, num);

			if(tails[index] == -1) {
				maxLen++;
			}
			tails[index] = num;
		}

		return n - maxLen;
	}

	public int findMinIndex(int[] tails, int n, int val) {
		int low = 0;
		int ans = n;
		int high = n - 1;

		while(low <= high) {
			int mid = (high + low) / 2;

			if(tails[mid] >= val) {
				ans = mid;
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
		return ans;
	}
}