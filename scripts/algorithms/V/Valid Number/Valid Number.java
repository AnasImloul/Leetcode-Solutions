// Runtime: 8 ms (Top 19.3%) | Memory: 44.65 MB (Top 6.2%)

class Solution {
    public boolean isNumber(String s) {
        try{
            int l=s.length();
            if(s.equals("Infinity")||s.equals("-Infinity")||s.equals("+Infinity")||s.charAt(l-1)=='f'||s.charAt(l-1)=='d'||s.charAt(l-1)=='D'||s.charAt(l-1)=='F')
            return false;
            double x=Double.parseDouble(s);
            return true;
        }
        catch(Exception e){
            return false;
        }
        
    }
}