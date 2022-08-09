class Solution {
    public boolean isValid(String s) {
        
        //Lets see how we can solve that as we know we have only abc in string.
        //Like           aabcbc
        // See as that   ((b)b) Think a is '(' and c is ')'.
        // If a string is made by using abc only we can remove abc to make it empty also.
        
        //Think in Reverse Way.
        
        
        
        Stack<Character> stack = new Stack<>();
        char[] arr = s.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            
            // We have to work only when we get ')' means c.
            
            if(arr[i] == 'c')
            {
                // If we at c means we have 2 elements before us a and b.
                // When we first pop we get b at second pop we get a
                
            // If this all hold true we will delete a and b we are not adding c so c also
                
                if(stack.size()>=2 && stack.pop() == 'b' && stack.pop() == 'a')
                {

                }
                else
                {
                    
                    // If anywhere we get false in any condition that means this is not a                          valid set i.e. abc pattern is not present.
                    
                    return false;
                }
            }
            else
            {
                // For a and b we simply add.
                
                stack.push(arr[i]);
            }
        }
        
        //If we have only abc pattern the stack will become empty.
        
        return stack.size()==0;
    }
}
