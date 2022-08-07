class Solution {
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        int n = heights.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] width = new int[n];
        
        for(int i=0; i<n; i++){
            while(!stack1.isEmpty() && heights[stack1.peek()] >= heights[i])
                stack1.pop();
            if(!stack1.isEmpty())
                left[i] = stack1.peek();
            else
                left[i] = -1;
            stack1.push(i);
        }
        
        for(int i=n-1; i>=0; i--){
            while(!stack2.isEmpty() && heights[stack2.peek()] >= heights[i])
                stack2.pop();
            if(!stack2.isEmpty())
                right[i] = stack2.peek();
            else
                right[i] = n;
            stack2.push(i);
        }
        
        for(int i=0; i<n; i++){
            width[i] = right[i] - left[i] - 1;
        }
        int mxArea = 0;
        for(int i=0; i<n; i++){
            mxArea = Math.max(mxArea, width[i] * heights[i]);
        }        
        return mxArea;
    }
}
