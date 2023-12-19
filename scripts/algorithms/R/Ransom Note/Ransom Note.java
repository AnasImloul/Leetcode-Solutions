// Runtime: 17 ms (Top 19.48%) | Memory: 44.60 MB (Top 8.88%)

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        char[] rs = ransomNote.toCharArray();
        char[] ms = magazine.toCharArray();
        
        HashMap<Character, Integer> rm = new HashMap<>();
        HashMap<Character, Integer> mz = new HashMap<>();
        
        for (char c : rs) {
            if (rm.containsKey(c)) {
                rm.put(c, rm.get(c) + 1);
            } else {
                rm.put(c, 1);
            }
        }

        for (char c : ms) {
            if (mz.containsKey(c)) {
                mz.put(c, mz.get(c) + 1);
            } else {
                mz.put(c, 1);
            }
        }

        for (char c : rm.keySet()) {
            if (!mz.containsKey(c) || mz.get(c) < rm.get(c)) {
                return false;
            }
        }
        return true;  
    }
}
