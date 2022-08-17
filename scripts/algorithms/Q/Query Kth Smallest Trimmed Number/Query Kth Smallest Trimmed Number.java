class Solution {
    public int[] smallestTrimmedNumbers(String[] nums, int[][] queries) {

        if (nums.length == 0)
            return new int[0];

        int[] result = new int[queries.length];
        int strLen = nums[0].length();
        int[] index = new int[1];
		
        PriorityQueue<Integer> queue = new PriorityQueue<>((a, b) -> {
            for (int i = index[0]; i < strLen; i++) {
                if (nums[a].charAt(i) != nums[b].charAt(i))
                    return nums[b].charAt(i) - nums[a].charAt(i);
            }

            return b - a;
        });

        for (int i = 0; i < queries.length; i++) {
            index[0] = strLen - queries[i][1];
            queue.clear();

            for (int j = 0; j < nums.length; j++) {
                queue.add(j);
                if (queue.size() > queries[i][0])
                    queue.poll();
            }

            result[i] = queue.poll();
        }

        return result;
    }
}
