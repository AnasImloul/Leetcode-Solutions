class Solution {
    public boolean digitCount(String num) {
        int[] freqArr = new int[10];  // n = 10 given in constraints;
        
        
        for(char ch : num.toCharArray()){
            freqArr[ch-'0']++;
        }
        
        for(int i=0;i<num.length();i++){
            int freq = num.charAt(i)-'0';  //freq of each indexValue;
            freqArr[i] = freqArr[i] - freq; 
        }
        for(int i=0;i<10;i++){
            if(freqArr[i]!=0){
                return false;
            }
        }
        return true;
    }
}
