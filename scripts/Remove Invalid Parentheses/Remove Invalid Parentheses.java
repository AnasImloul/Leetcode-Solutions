class Solution {
    public List<String> removeInvalidParentheses(String s) {
        
        int minInvalid = minInvalidParenthesis(s);
        List<String> resList = new ArrayList<String>();
        removeInvalidParenthesesHelper(s, minInvalid, resList, new HashSet<String>());
        return resList;
        
    }
    
    private void removeInvalidParenthesesHelper(String s, int invalidCount, List<String> resList, HashSet<String> checkSet){
        
        if(invalidCount == 0){
            if(minInvalidParenthesis(s) == 0){
                if(!checkSet.contains(s)){
                    checkSet.add(s);
                    resList.add(s);
                }    
            }
            return;
        }
        
        for(int i=0; i<s.length(); i++){
            if(s.charAt(i) == '(' || s.charAt(i) == ')'){
                String stringAfterRemoval = s.substring(0,i) + s.substring(i+1);
                if(!checkSet.contains(stringAfterRemoval)){
                    checkSet.add(stringAfterRemoval);
                    removeInvalidParenthesesHelper(stringAfterRemoval, invalidCount-1, resList, checkSet);
                }
            }    
            
        }
        
        
    }
    
    private int minInvalidParenthesis(String s){
        Stack<Character> stack = new Stack();
        
        for(int i=0; i<s.length(); i++){
            Character ch = s.charAt(i);
            
            if(ch == '('){
                stack.push(ch);
            }else if(ch == ')'){
                
                if(stack.size()>0){
                    if(stack.peek() == '('){
                        stack.pop();
                    }else if(stack.peek() == '('){
                        stack.push(ch);
                    }
                }else{
                    stack.push(ch);
                }    
            }
        }
        return stack.size();
    }
}
