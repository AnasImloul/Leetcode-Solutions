class Solution {
    public int bitwiseComplement(int n) {
        
        String conversion = Integer.toBinaryString(n);
        String temp = "";
        for(int i = 0; i < conversion.length(); i++){
            if(conversion.charAt(i) == '0'){
                temp += "1";
            }
            else{
                temp += "0";
            }
        }
        int complement = Integer.parseInt(temp, 2);
        return complement;
    }
}
