class Solution {
    public int maxVowels(String s, int k) {
        int max=0,cnt=0;
        for(int i=0,j=0;j<s.length();j++){
            if(j-i+1<k){
                if(s.charAt(j)=='a' ||s.charAt(j)=='e' || s.charAt(j)=='i' || s.charAt(j)=='o' || s.charAt(j)=='u' ){
                    cnt++;
                }
            }
            else{
                if(s.charAt(j)=='a' ||s.charAt(j)=='e' || s.charAt(j)=='i' || s.charAt(j)=='o' || s.charAt(j)=='u'){
                    cnt++;
                }
                max=Math.max(max,cnt);
                if(s.charAt(i)=='a' ||s.charAt(i)=='e' || s.charAt(i)=='i' || s.charAt(i)=='o' || s.charAt(i)=='u'){
                    cnt--;
                }
                i++;
            }
            
        }
        return max;
    }
}
