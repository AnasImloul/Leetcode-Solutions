class Solution{
	public boolean checkValidString(String s){
		Stack<Integer> stack = new Stack<>();
		Stack<Integer> star = new Stack<>();
		for(int i=0;i<s.length();i++){
			if(s.charAt(i)=='(' ) 
                stack.push(i);
            else if(s.charAt(i)=='*') 
                star.push(i);
			else {
                if(!stack.isEmpty())
                         stack.pop();
                
               else if(!star.isEmpty())
                          star.pop();
                 else 
                          return false;
                
			}
		}
        while(!stack.isEmpty()){
            if(star.isEmpty()) 
                return false;
            else if( stack.peek()<star.peek())                
            {
                star.pop();
                stack.pop();
            }
            else
                 return false;
        }
		return true;
	}
}
