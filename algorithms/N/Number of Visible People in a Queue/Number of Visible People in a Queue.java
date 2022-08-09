class Solution {
    public int[] canSeePersonsCount(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        int result[] = new int[heights.length];
        for(int i = heights.length - 1; i >= 0; i--) {
            int visibility = 0;
            while(!stack.isEmpty() && heights[i] > stack.peek()) {
                stack.pop();
                visibility++;
            }
            if(!stack.isEmpty()) visibility++;
            stack.push(heights[i]);
            result[i] = visibility;
        }
        return result;
    }
}
