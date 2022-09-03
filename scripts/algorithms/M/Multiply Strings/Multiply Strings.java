// Runtime: 17 ms (Top 37.52%) | Memory: 44.4 MB (Top 28.50%)
class Solution {
    public String multiply(String num1, String num2) {
        if(num1.equals("0") || num2.equals("0"))
            return "0";
        int[] arr=new int[num1.length()+num2.length()];

        int index=0;
        for(int i=num1.length()-1;i>=0;i--)
        {
            int carry=0;
            int column=0;
            for(int j=num2.length()-1;j>=0;j--)
            {
                int a=(num1.charAt(i)-'0')*(num2.charAt(j)-'0');
                int temp=(arr[index+column]+carry+a);
                arr[index+column]=temp%10;
                carry=temp/10;
                column++;
            }
            if(carry!=0)
            {
                arr[index+column]=carry;
            }
            index++;
        }
        String ans="";
        index=arr.length-1;
        while(arr[index]==0)
        {
            index--;
        }
        for(int i=index;i>=0;i--)
        {
            ans+=arr[i];
        }
        return ans;
    }
}