class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int i= a.length() -1;
        int j= b.length() -1;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0)
                sum+=a.charAt(i--)-'0'; // -'0' is just to convert char in integer
            if(j>=0)
                sum+=b.charAt(j--)-'0';
            sb.append(sum%2);   // If we have sum = 1  1  then = 2 % 2 = 0 and 0  1 = 1 % 2 = 1
            carry = sum /2;
        }
        if(carry>0)
            sb.append(carry);
        return sb.reverse().toString();
    }
}
