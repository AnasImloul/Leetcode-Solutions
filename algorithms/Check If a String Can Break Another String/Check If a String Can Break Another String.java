class Solution {
    public boolean checkIfCanBreak(String s1, String s2) {
        int n = s1.length();
        char[] one = s1.toCharArray();
        char[] two = s2.toCharArray();
        Arrays.sort(one);
        Arrays.sort(two);
        if(check(one,two,n) || check(two,one,n)){
            return true;
        }
        return false;
    }
    public boolean check(char[] one,char[] two,int n){
        for(int i=0;i<n;i++){
            if(one[i]-'a'>two[i]-'a'){
                return false;
            }
        }
        return true;
    }
}