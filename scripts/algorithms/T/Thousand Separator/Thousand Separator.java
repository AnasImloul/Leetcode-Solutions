class Solution {
    public String thousandSeparator(int n) {
        if(n==0) return "0";
       StringBuilder str = new StringBuilder();
        int count=0;
       while(n>0){
           int lastDigit = n%10;
           if(count%3==0 && count!=0){
               str.append(".");
           }
           str.append(lastDigit);
           count++;
           n = n/10;
       }
        return str.reverse().toString();
    }
}