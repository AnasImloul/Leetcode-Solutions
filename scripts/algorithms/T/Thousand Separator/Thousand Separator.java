// Runtime: 0 ms (Top 100.0%) | Memory: 39.69 MB (Top 67.9%)

class Solution {
    public String thousandSeparator(int n) {
       
        StringBuffer str = new StringBuffer(Integer.toString(n));
        int index = str.length() - 3;
        
        while(index >= 1){
            str.insert(index , '.');
            index = index - 3;
        }
        
        return str.toString();
    }
}