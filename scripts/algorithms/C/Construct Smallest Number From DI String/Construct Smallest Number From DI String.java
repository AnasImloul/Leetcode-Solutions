// Runtime: 1 ms (Top 80.2%) | Memory: 40.62 MB (Top 53.2%)

class Solution {
    public String smallestNumber(String pattern) {
        Stack<Integer> stack = new Stack<>();
        for (int i = 9; i >= 1; i--) {
            stack.push(i);
        }
        Stack<Integer> stackTemp = new Stack<>();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);
            if (c == 'I') {
                sb.append(stack.pop());
                while (stackTemp.size() > 0) {
                    sb.append(stackTemp.pop());
                }
            } else {
                if (i - 1 > 0 && pattern.charAt(i - 1) != c) {
                    while (stackTemp.size() > 0) {
                        sb.append(stackTemp.pop());
                    }
                }
                stackTemp.push(stack.pop());
            }
        }
        stackTemp.push(stack.pop());
        while (stackTemp.size() > 0) {
            sb.append(stackTemp.pop());
        }
        return sb.toString();
    }
}