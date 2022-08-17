class Solution {

StringBuilder sb;

public int numSteps(String s) {
    int count  = 0; 
    
    sb = new StringBuilder(s);
    
    while (sb.length() > 1) {
        if ( sb.charAt(sb.length() - 1) == '1') { // odd number 
            addOne();        
        } else {
            sb.deleteCharAt(sb.length() - 1);  // divide by 2
        }
        
        count ++; 
        //System.out.println(sb.toString());
    }
    
    return count; 
}

public void addOne()    {
    for (int i = sb.length() - 1; i>=0; i--) {
        if (sb.charAt(i) == '0') {
            sb.setCharAt(i, '1'); // flip bits and stop at first zero; 
            return; 
        } else {
            sb.setCharAt(i, '0');   // flip bit and continue to next position 
        }
    }
    
    sb.insert(0, '1');
    return; 
}
