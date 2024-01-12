// Runtime: 0 ms (Top 100.0%) | Memory: 44.10 MB (Top 77.94%)

class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        char res=letters[0];
        int start=0;
        int end=letters.length-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(letters[mid]==target)
            {
                start=mid+1;
            }
            else if(target>letters[mid])
            {
                start=mid+1;
            }
            else if(letters[mid]>target)
            {
                res=letters[mid];
                end=mid-1;
            }
        }
        return res;
        
    }
}
