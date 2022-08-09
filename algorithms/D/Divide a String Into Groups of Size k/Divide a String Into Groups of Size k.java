class Solution {
    public String[] divideString(String s, int k, char fill) {
        int rem = 0;
        if( s.length() % k != 0){
             rem = k - s.length() % k; //counting the total positions where we have to fill the char "fill".
        }
        for(int i = 0; i < rem; i++){
            s = s+fill; //appending the char to the String
        }
        
        String[] strs = new String[s.length()/k];  //the length will be String length / K because we are making pair of k length Strings.
        int index = 0;  //index for array.
        for(int i = 0; i < s.length(); i+=k){
            strs[index] = s.substring(i, i+k); //substing of  current element to Kth element. 
            index++;
        }
        return strs;
    }
}
