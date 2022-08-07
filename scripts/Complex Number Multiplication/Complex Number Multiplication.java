class Solution {
    public String complexNumberMultiply(String num1, String num2) {
        int val1 = Integer.parseInt(num1.substring(0, num1.indexOf('+')));
        int val2 = Integer.parseInt(num1.substring(num1.indexOf('+')+1,num1.length()-1));
        int val3 = Integer.parseInt(num2.substring(0, num2.indexOf('+')));
        int val4 = Integer.parseInt(num2.substring(num2.indexOf('+')+1,num2.length()-1));
        
        return "" + (val1*val3 - val2*val4) + "+" + (val1*val4 + val3*val2) + "i";
    }
}
