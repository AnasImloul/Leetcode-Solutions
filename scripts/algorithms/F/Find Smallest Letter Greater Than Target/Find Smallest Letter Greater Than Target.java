class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int start=0,end=letters.length-1;
    while(start<=end){
      int mid=start+(end-start)/2;
      if(letters[mid]>target){    //strictly greater is the solution we want
        end = mid-1;
      }else{
        start=mid+1;
      }
    }
    return letters[start % letters.length];    // this is the wrap around condition , we use modulo %
    }
}
