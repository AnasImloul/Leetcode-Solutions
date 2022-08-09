class Solution {
    public int dayOfYear(String date) {
        int[] months = {31,28,31,30,31,30,31,31,30,31,30,31};
        int year = (date.charAt(0)-48)*1000+(date.charAt(1)-48)*100+(date.charAt(2)-48)*10+date.charAt(3)-48;
        if(year%4==0 && year!=1900){
            months[1]++;
        }
        int ans = 0;
        for(int i=0;i<((date.charAt(5)-48)*10)+date.charAt(6)-48-1;i++){
            ans += months[i];
        }
        ans += (date.charAt(8)-48)*10+date.charAt(9)-48;
        return ans;
    }
}