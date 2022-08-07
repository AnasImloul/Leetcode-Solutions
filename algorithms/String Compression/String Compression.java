class Solution {
    public int compress(char[] chars) {
        int pt1=0,pt2=1; // pt1 is slow pointer to update chars & pt2 is fast pointer to calculate the count for pt1;
        int count=1; // since every element will occur atleast once.
        for(;pt2<chars.length;pt2++){
            if(chars[pt2]==chars[pt2-1]){
                count++;
            }
            else {
                chars[pt1] = chars[pt2-1]; // change pt1 to last same character
                pt1 = setGroupCount(count,chars,++pt1); // if (count > 1) then update chars with count
                count=1; // reset to 1 for new element
            }
        }
        chars[pt1] = chars[pt2-1];          // same as above else block for last element
        return setGroupCount(count, chars, ++pt1); 
    }
    
    private int setGroupCount(int count,char[] chars, int pt){
        if(count>1){
            String str = String.valueOf(count);
            for(int i=0;i<str.length();i++)
                chars[pt++]=str.charAt(i);
            }
        return pt;
    }
}
