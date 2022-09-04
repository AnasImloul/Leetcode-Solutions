// Runtime: 1 ms (Top 90.26%) | Memory: 41.4 MB (Top 23.64%)
class Solution {
    public int maximumSwap(int num) {
        char str[]=String.valueOf(num).toCharArray();
        char arr[]=str.clone();
        Arrays.sort(arr);
        int i=0;
        int j=str.length-1;
        while(i<str.length && j>=0 && arr[j]==str[i]){i++;j--;}
        int search=j;
        if(i==str.length) return num;
        j=str.length-1;
        while(arr[search]!=str[j]){j--;}

        char c=str[i];
        str[i]=str[j];
        str[j]=c;
        return Integer.parseInt(new String(str));
    }
}