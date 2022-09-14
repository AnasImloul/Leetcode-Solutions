// Runtime: 1 ms (Top 90.35%) | Memory: 40.8 MB (Top 87.29%)
class Solution {
    public String reverseOnlyLetters(String s) {
        // converting the string to the charArray...
        char[] ch = s.toCharArray();

        int start = 0;
        int end = s.length()-1;

        // Storing all the english alphabets in a hashmap so that the searching becomes easy...
        HashMap<Character , Integer> hash = new HashMap<>();
        for(int i=0 ; i<26 ;i++){
            hash.put((char)(97+i) , 1);
        }
        for(int i=0 ; i<26 ; i++){
            hash.put((char)(65+i) , 1);
        }

        // using two while loops ..since the constraints are too less thats why we can prefer nested loops approach..
        while(start<end){

            // interating untill start pointer reacher a good character
            while(start<end&&!hash.containsKey(ch[start])){
                start++;
            }
            // iterating untill the end pointer reaches the good character..
            while(end>start&&!hash.containsKey(ch[end])){
                end--;
            }

            // swapping the array elements..
            char temp = ch[start];
            ch[start] = ch[end];
            ch[end] = temp;

            start++;
            end--;
        }

        // converting the charArray to the string again..
        String ans = new String(ch);
        return ans;

        // Time Complexity : O(N) (since the loops will run only till the number of charcters in the string..)
        // Space Complexity : O(N) since we used hashmap..
    }
}