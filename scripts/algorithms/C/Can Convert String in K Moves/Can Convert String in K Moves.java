// Runtime: 23 ms (Top 58.97%) | Memory: 54.5 MB (Top 69.23%)
class Solution {
    public boolean canConvertString(String s, String t, int k) {
       //if strings lengths not equal return false
        if(s.length()!=t.length())return false;
       //array to count number of times a difference can repeat
        int b[]=new int[26];
        int h=k/26;
        int h1=k%26;
        //count of each number from 1 to 26 from 1 to k
        for(int i=0;i<26;i++){
            b[i]+=h;
            if(i<=h1)b[i]++;
        }

       int i=0;
        while(i<s.length()){
            //if both characters equal increment i
            if(s.charAt(i)==t.charAt(i)){
                i++;
            }else{
                //else now find difference
                //+26 because we dont know it can be negative also and again mod with 26
                int diff=((t.charAt(i)-s.charAt(i))+26)%26;
                //decrement count after usage of one value of b[diff]
                b[diff]--;
                //if b[diff]<0 means over usage than given so return false
                if(b[diff]<0) return false;
                //else finally increment
                else i++;
            }

        }
        return true;
    }
}