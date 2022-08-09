class Solution {
    public int[] movesToStamp(String stamp, String target) {
        
        /*
        * Intitution:
        * Instead of creating target string from intial state,
        * create the intial state from the target string.
        * - take a window of stamp length
        * - reverse that window to the intail state 
        *  current state -> abcdefgh, window = def, 
        *  next state    -> abc???gh 
        *
        */
        
        int sLen = stamp.length();
        int tLen = target.length();
        
        //it save the index of reversed charcacter
        Queue<Integer> reversedCharIndices= new LinkedList();
        
        //it mark Character of target, as reversed
        boolean[] isReversedCharOfThisIndex = new boolean[tLen];
        
        Stack<Integer> stack = new Stack();
        
        List<Window> widowList = new ArrayList();
        
        for(int windowStartIndex = 0; windowStartIndex <= tLen - sLen; windowStartIndex++){
            
            Set<Integer> matched = new HashSet();
            Set<Integer> notMatched = new HashSet();
            
            for(int j = 0; j < sLen; j++){
                
                //char index of current window of the target
                int charIndex = windowStartIndex + j;
                
                if(stamp.charAt(j) == target.charAt(charIndex)){
                    matched.add(charIndex);
                } else {
                    notMatched.add(charIndex);
                }
            }
            
            //add the window
            widowList.add(new Window(matched, notMatched));
            
            //when all char of current window is matched with 
            if(notMatched.isEmpty()){
                stack.push(windowStartIndex);
                
                for(int index : matched){
                    if(!isReversedCharOfThisIndex[index]){
                        
                        //add in queue, so that we can process,
                        //another window which is affected by its character get reversed
                        reversedCharIndices.add(index);
                        
                        //mark it reversed
                        isReversedCharOfThisIndex[index] = true;
                    }
                }
                
            }
        }
        
        
        
        //get all char index, one by once
        //see the impact of reverse char of this index, in ano
        while(!reversedCharIndices.isEmpty()){
            int reversedCharIndex = reversedCharIndices.remove();
            
            int start =  Math.max(0, reversedCharIndex - sLen + 1);
            int end   =  Math.min(reversedCharIndex, tLen - sLen);
            
            for(int windowIndex = start; windowIndex <= end; windowIndex++){
                
                if(widowList.get(windowIndex).notMatched.contains(reversedCharIndex)){
                    
                   
                    //as this char is reversed in another window
                    //remove this char index from current window, 
                    widowList.get(windowIndex).notMatched.remove(reversedCharIndex);
                    
                    if(widowList.get(windowIndex).notMatched.isEmpty()){
                        
                        //as all of charcater reversed of current window
                        //now add current window index
                        stack.push(windowIndex);
                        
                        for(int index : widowList.get(windowIndex).matched){
                            
                            if(!isReversedCharOfThisIndex[index]){

                                //add in queue, so that we can process,
                                //another window which is affected by its character get reversed
                                reversedCharIndices.add(index);

                                //mark it reversed
                                isReversedCharOfThisIndex[index] = true;
                            }
                        }
                    }
                }
                
            }
        }
        
            
        for(boolean reversed : isReversedCharOfThisIndex){
            if(!reversed){
                return new int[0];
            }
        }
        
        int i = 0;
        int[] result = new int[stack.size()];
        while(!stack.empty()){
            result[i++] = stack.pop();
        }
        
        
        return result;
        
    }
}

class Window {
    Set<Integer> matched;
    Set<Integer> notMatched;
    
    public Window(Set<Integer> matched, Set<Integer> notMatched){
        this.matched = matched;
        this.notMatched = notMatched;
    }
}
