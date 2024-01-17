// Runtime: 6 ms (Top 65.57%) | Memory: 44.90 MB (Top 59.84%)

class Solution {
    public int minimumBuckets(String street) {
        int count=0;
        for(int i=0;i<street.length();i++){
            if(street.charAt(i)=='H'){
                if(i+1<street.length() && street.charAt(i+1)=='.'){
                    count++;
                    i+=2;
                    continue;
                }
                if(i-1>=0 && street.charAt(i-1)=='.'){
                    count++;
                    continue;
                }
                return -1;
            }
        }
        return count;
    }
}