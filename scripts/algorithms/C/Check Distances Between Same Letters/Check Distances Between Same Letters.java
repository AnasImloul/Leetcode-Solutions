// Runtime: 2 ms (Top 40.7%) | Memory: 41.77 MB (Top 46.5%)

/*
Use map to store the character and the index of its first occurance
And when the second occurance found, count the elemnets in between
and check in distance[] whether the distance at the place is correct or not
*/
class Solution {
    public boolean checkDistances(String s, int[] distance) {
        
        Map<Character,Integer> map = new HashMap<>();
        char[] arr = s.toCharArray();
        int len = arr.length;
        
        for(int i=0; i<len; i++){
            if(map.containsKey(arr[i])){
                int start = map.get(arr[i]);
                int diff = i - start - 1;
                if(distance[arr[i]-'a'] != diff) return false;
            }
            else map.put(arr[i], i);
        }
        return true;
    }
}