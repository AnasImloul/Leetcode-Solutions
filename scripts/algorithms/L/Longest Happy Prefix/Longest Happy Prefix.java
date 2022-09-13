// Runtime: 13 ms (Top 89.72%) | Memory: 43.2 MB (Top 90.81%)
class Solution {
    public String longestPrefix(String s) {
       int n=s.length();
        char arr[] = s.toCharArray();
        int lps[]=new int[n];
        for(int i=1; i<n; i++){
            int j=lps[i-1]; // COMPARING ITS i WITH ITS PREV ELEMENT
            while(j>0 && arr[j]!=arr[i]){
                j=lps[j-1]; // DEACREASING TILL WE FIND ITS PREFIX WHICH IS EQUAL TO ITS SUFFIX
            }
            if(arr[j]==arr[i]){// IF ITS PREV IS SAME AS CURRENT THEN INCREAMENT IT
                j++;
            }
            lps[i]=j; // SAVE WHATEVER THE VALUE IS
        }
        int j=lps[n-1];
       StringBuilder sb = new StringBuilder();
        for(int i=0;i<j;i++){
            sb.append(arr[i]);
        }
        return sb.toString();

    }
}
/*
 ALTERNATE

  for(int i=1;i<n;i++){
            if(arr[i]==arr[j]){ // IF SAME INCREASE IT
                lps[i]=++j;
            }else if(j>0){ // ELSE DEACREASE TILL WE ARE NOT FINDING IT
                j=lps[j-1];
                i--;
            }
        }
        return s.substring(0,j);

 */