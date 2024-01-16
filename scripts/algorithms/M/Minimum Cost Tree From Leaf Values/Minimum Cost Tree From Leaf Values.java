// Runtime: 1 ms (Top 95.15%) | Memory: 41.70 MB (Top 26.54%)

class Solution {
    // Use stack. Similar to trapping the rain water problem and the largest rectangle under histogram
    // Use stack to keep a decreasing order by adding smaller values, while there is bigger value 
    //arr[i] than the peek, pop it and store as mid and calculate the multiplication mid*min(arr[i],  
    //stack.peek()).
    
    // NOTE: if we observe the number array, in order to obtain the smallest sum of all non-leaf
    // values, we want to merge those small values first. In order words, the smaller a value
    // is, the lower leaf it should stay because this way as we are building the tree up, 
    // we are building smaller multiplication/parent node first as it is only going to get bigger
	// as we build the tree up. 
    
    // Ex: 4 3 2 1 5
    // There are many ways we can build a tree following the problem's requirement. However, to 
    // gain smallest sum. We need to merge 2 and 1 first as they are the two smallest ones. To
	// do that, we use the stack mentioned above as a decreasing order. After
    // that we get a parent node with value 2. This node could be a left or right child of its parent
    // but what we want is that its parent needs also be as small as possible. We also know that its
    // parent has one mutiplier already: 2. Note: this 2 is not from the product of 1 * 2, but from the max  of child
    // 1 and 2 as the problem requires. So, we see what values next to the leaf 2 could be a 
	// candidate. Obviously, 3 since it is the smallest one in the stack Then, 3
    // becomes the left child and 1*2 = 2 becomes right child. See below: 
    //  ...
    //  / \
    // 3   2
    //    / \
    //   2   1
    // 
    
    // If we observe carefully, 3 2 1 is decreasing... So how about every time we see a "dip" point
    // in the array we calculate its multiplication. To do that, say we are at arr[i] and their 
    // relations are arr[i-1] <= arr[i] <= arr[i+1]. The min multiplication is a[i] * min(arr[i-1], 
    // arr[i+1]). Then the example above is arr[i] = 1, arr[i-1] = 2, arr[i+1] = 5
    
    public int mctFromLeafValues(int[] arr) {
          if(arr == null || arr.length < 2){
              return 0;
          }
          
          int res = 0;
          Stack<Integer> stack = new Stack<>();          
          for(int num : arr){
              
             // while num is bigger than peek(), pop and calculate
             while(!stack.isEmpty() && stack.peek() <= num){
                 int mid = stack.pop();
                 if(stack.isEmpty()) 
                     res += mid * num;
                 else
                    res += mid * Math.min(stack.peek(), num);
             }
             
             stack.push(num); // if num is smaller, push into stack
         }
         
         // if there are values left in the stack, they sure will be mutiplied anyway
         // and added to the result. 
         while(stack.size() > 1){ // > 1 because we have a peek() after pop() below
             res += stack.pop() * stack.peek();
         }
         
         return res;
    }
}
