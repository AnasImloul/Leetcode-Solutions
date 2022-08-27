// Runtime: 1 ms (Top 73.53%) | Memory: 41.8 MB (Top 76.89%)
class Solution {
    public int[] numberOfLines(int[] widths, String s) {
            int sum=0,count=0;
            for(int j=0;j<s.length();j++)
            {
                int pos = s.charAt(j)-'a';
                sum+=widths[pos];
                if(sum>100)
                {
                    j--;
                    count++;
                    sum=0;
                    continue;
                }
            }
        int[] arr = new int[2];
        arr[0]=count+1;
        arr[1]=sum;
        return arr;
    }
}