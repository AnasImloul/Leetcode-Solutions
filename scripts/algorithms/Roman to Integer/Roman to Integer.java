class Solution {
    public int romanToInt(String s) {
        
        HashMap<Character, Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        
        int value = 0, preVal = 0;
        
        for(int i=s.length()-1; i>=0; i--) {
            int val = map.get(s.charAt(i));
            if(val < preVal) {
                value -= val;
            }
            else {
                value += val;
            }
            preVal = val;
        }
        
        return value;
    }
}
