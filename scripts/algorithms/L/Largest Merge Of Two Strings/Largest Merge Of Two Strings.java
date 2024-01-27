// Runtime: 18 ms (Top 92.79%) | Memory: 44.70 MB (Top 66.67%)

class Solution {
    public String largestMerge(String word1, String word2) {
        StringBuilder sb = new StringBuilder();
        int i=0;
        int j=0;
        char[] w1 = word1.toCharArray();
        char[] w2 = word2.toCharArray();
        
        int n1=w1.length;
        int n2=w2.length;
        
        // we loop until we exhaust any one of the 2 words completely
        while(i<n1 && j<n2){
            
            // if both the characters are equal we choose the one where the next largest occurs earlier
            if(w1[i]==w2[j]){
                if(check(w1,i,w2,j)){
                    sb.append(w1[i++]);
                }else{
                    sb.append(w2[j++]);
                }
            }
            
            // else we greedily choose the largest of the two characters
            else if(w1[i]>w2[j]){
                sb.append(w1[i++]);
            }else{
                sb.append(w2[j++]);
            }
        }
        
        // at the end of the loop we append any remaining word
        sb.append(word1.substring(i));
        sb.append(word2.substring(j));
		
        return sb.toString();
    }
    
    private boolean check(char[] w1, int i, char[] w2, int j){
        // will return true if we need to extract from word1 and false if we need to extract from word2
        
        while(i<w1.length && j<w2.length){
            if(w1[i]==w2[j]){
                i++;
                j++;
            }
            else if(w1[i]>w2[j]){
                return true;
            }else{
                return false;
            }
        }
        
        // if we are unable to find any exhaustable character till the end of the loop we use the one having larger length
        if(i<w1.length){
            return true;
        }
        return false;
    }
}
