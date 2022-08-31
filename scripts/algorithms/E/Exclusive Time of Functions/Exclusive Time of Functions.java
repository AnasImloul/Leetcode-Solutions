// Runtime: 26 ms (Top 31.28%) | Memory: 52.6 MB (Top 22.01%)
class Solution {

    //Time Complexity: O(N) for looping through logs
    //Space Complexity: O(N) for stack

    public int[] exclusiveTime(int n, List<String> logs) {
        if (n == 0) {
            return new int[0];
        }

        int[] result = new int[n];

        Stack<Pair<Integer, Integer>> stack = new Stack<>();

        for (String s : logs) {
            String[] sArr = s.split(":");
            int functionId = Integer.parseInt(sArr[0]);
            String startOrEnd = sArr[1];
            int timestamp = Integer.parseInt(sArr[2]);

            if (startOrEnd.equals("start")) {

                //calculate previous in-progress length
                if (!stack.empty()) {
                    Pair<Integer, Integer> pair = stack.peek();
                    int oldFunctionId = pair.getKey();
                    int oldTimestamp = pair.getValue();
                    result[oldFunctionId] += timestamp - oldTimestamp;
                }

                //add new start
                stack.push(new Pair(functionId, timestamp));
            } else {
                //calculate current length
                Pair<Integer, Integer> pair = stack.pop();
                int oldTimestamp = pair.getValue();

                result[functionId] += timestamp - oldTimestamp + 1;

                //reset previous function's start
                if (!stack.empty()) {
                    pair = stack.pop();
                    Pair<Integer, Integer> replacementPair = new Pair(pair.getKey(), timestamp + 1);
                    stack.push(replacementPair);
                }
            }
        }

        return result;
    }
}