// Runtime: 0 ms (Top 100.0%) | Memory: 40.99 MB (Top 67.1%)

class Solution {
    public List<String> removeComments(String[] source) {
        boolean blockActive = false; //We keep track of whether or not we are within a block comment with the blockActive variable. 
		//It is initally set to false since we haven't read anything until now. 


        List<String> result = new ArrayList<String>();
        StringBuilder builder = new StringBuilder();
        
        //Read every line from the source input. 
        
        for(String line: source){
// Each time we move on to reading a new line, we check if it is a part of a block comment. 
//If it is already part of a block comment, it means we should skip the implicit newline characters as mentioned in the problem description. 
//For example if Line 1 was  "int a /*Block comment Started" and Line 2 was "Block comment ends here */ b;", and Line 3 was "int c;" 
//we want our output to be "int ab", "int c" instead of "int a", "b;", "int c;" 
            if(!blockActive){ 
                builder = new StringBuilder();
            }
            for(int i=0; i<line.length(); i++){ //Read every character of line
                char c = line.charAt(i);
                if(!blockActive){ //If we aren't currently in a block
                    
                    if(c=='/'){ //We check if we encounter the start of a regular comment
                        //If so, then we need to check if the next character makes it a regular comment, a block comment, or neither of those two. 
                        
                        if(i<line.length()-1 && line.charAt(i+1)=='/'){ //Checking if it's a regular comment
                            break; //If it's a regular comment, we can simply skip everything else 
							//until the end of the line, so we break from the loop and move on to the next line.
                        } else if(i<line.length()-1 && line.charAt(i+1)=='*'){ //Or a block comment
                            i++; //Since we verified it's a block comment, we simply increment i so that we don't re-read the '*' again, 
							//and mark that we are now part of a block comment. 
                            blockActive = true;
                        } else{ // If the second character is neither a / or *, it indicates that a first character must be a valid operator 
						//(probably a mathematical operator such as multiplication or division, and not part of any comment, 
						//so simply append it to the builder)
                            builder.append(c);
                        }
                    } else  { //Append all other characters directly to the builder. 
                        builder.append(c);
                    }
                } else {
                    //We skip all other characters in a block comment, and check for the closing block comment. 
					//Once we find it, we mark the blockActive variable as false to indicate that it isn't part of the block anymore.  
                    if(c=='*'){
                        if(i<line.length()-1 && line.charAt(i+1)=='/'){
                              blockActive = false;  
                              i++;
                        }
                    }
                } 
            }
            //We append to the result when we aren't part of a block any more, and the builder contains 1 or more characters. 
            if(!blockActive && builder.length()!=0){
                result.add(builder.toString());
            }
            
        }
        
        return result;
        
    }
}