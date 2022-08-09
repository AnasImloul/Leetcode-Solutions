class Solution {
    public String maximumNumber(String num, int[] change) {
        int i=0, n=num.length(), startIndex=-1, substringLength=0;
        
        // traverse through each digit in the input string
        while(i<n) {
            int digit=num.charAt(i)-48;
            // when we encounter a digit which has greater change
            if(change[digit] > digit) {
                startIndex = i;
                // keep on replacing subsequent characters with with the change if they also have greater change
                while(i<n) {
                    digit=num.charAt(i)-48;
                    if(change[digit] < digit) {
                        break;
                    }
                    i+=1;
                }
                substringLength = i-startIndex;
                break;
            }
            i+=1;
        }
        
        // Note: Using String Builder to ensure linear time complexity as java strings are immutable
        StringBuilder result=new StringBuilder("");
        for(int j=0; j<n; j++) {
            int digit=num.charAt(j)-48;
            if(j>=startIndex && j<startIndex+substringLength) {
                result.append(change[digit]);    
            } else {
                result.append(digit);   
            }
        }
        
        return result.toString();
    }
}
