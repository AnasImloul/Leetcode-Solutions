class Solution {
    public int mctFromLeafValues(int[] arr) {
        
        int sum = 0;
        Stack<Integer> stack = new Stack<>();
        for (int num: arr) {
            sum += cleanUpStack(num, stack);
        }
        sum += cleanUpStack(17, stack);
        
        return sum;
    }
    
    private int cleanUpStack(int target, Stack<Integer> stack) {
        int last = 0;
        int sum = 0;
        while (!stack.isEmpty() && stack.peek() <= target) {
            int cur = stack.pop();
            sum += last * cur;
            last = cur;
        }
        if (target != 17) {
            sum += target * last;
            stack.push(target);
        }
        return sum;
    }
}
