class Solution {
    public String addSpaces(String s, int[] spaces) {
        
        int j = 0,curr = 0;
        StringBuilder sb = new StringBuilder();
        while(curr<s.length()){
           
             if(j<spaces.length&&spaces[j]==curr){
                 
                sb.append(" ");
                j++;
    
                }
                sb.append(s.charAt(curr));
                curr++;

        }

        return sb.toString();
        
    }
}
