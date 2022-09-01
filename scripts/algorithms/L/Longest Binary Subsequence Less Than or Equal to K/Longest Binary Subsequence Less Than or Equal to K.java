// Runtime: 2 ms (Top 83.60%) | Memory: 42.5 MB (Top 46.76%)
class Solution {
    public int longestSubsequence(String s, int k) {
        int z=0;
        //count zero
        for(int i=0;i<s.length();i++)if(s.charAt(i)=='0')z++;

        int num=0,base=1,len=0;
        //take as many ones from right as possible until they do not make the num>k
        for(int i=s.length()-1;i>=0;i--){

            if(num+base>k)break;
            if(s.charAt(i)=='1'){
               num+=base;
            }
            else {
            //remove already taken zeros from zeros count
                z--;
            }
            base*=2;
            len++;
        }

        return len+z;
    }
}