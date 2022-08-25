// Runtime: 64 ms (Top 29.92%) | Memory: 46.6 MB (Top 92.25%)
class Solution {
    public int maximalRectangle(char[][] matrix) {
        ArrayList<Integer> list = new ArrayList<>();
        int n = matrix[0].length;
        for(int i=0; i<n; i++){
            list.add(Character.getNumericValue(matrix[0][i]));
        }

        int maxArea = maximumArea(list);
        int m = matrix.length;

        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '1'){
                    list.set(j, Character.getNumericValue(matrix[i][j]) + list.get(j));
                }else
                    list.set(j, 0);
            }
            maxArea = Math.max(maxArea, maximumArea(list));
        }
        return maxArea;
    }
    public int maximumArea(ArrayList<Integer> heights) {
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        int n = heights.size();
        int[] left = new int[n];
        int[] right = new int[n];
        int[] width = new int[n];

        for(int i=0; i<n; i++){
            while(!stack1.isEmpty() && heights.get(stack1.peek()) >= heights.get(i))
                stack1.pop();
            if(!stack1.isEmpty())
                left[i] = stack1.peek();
            else
                left[i] = -1;
            stack1.push(i);
        }

        for(int i=n-1; i>=0; i--){
            while(!stack2.isEmpty() && heights.get(stack2.peek()) >= heights.get(i))
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
            mxArea = Math.max(mxArea, width[i] * heights.get(i));
        }
        return mxArea;
    }
}