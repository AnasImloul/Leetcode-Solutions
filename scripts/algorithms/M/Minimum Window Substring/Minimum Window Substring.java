// Runtime: 98 ms (Top 16.21%) | Memory: 43.4 MB (Top 87.12%)
class Solution {
    public String minWindow(String s, String t) {
        HashMap<Character, Integer> child = new HashMap<>();
        HashMap<Character, Integer> parent = new HashMap<>();

        int left = -1, right = -1, match = 0;
        String window = "";

        for(int i = 0; i < t.length(); i++){
            char c = t.charAt(i);
            child.put(c, child.getOrDefault(c, 0) + 1); //Child frequency map
            }

        while(true){
            boolean f1 = false, f2 = false;

            while(right < s.length() - 1 && match < t.length()){
                right++;
                char c = s.charAt(right);
                parent.put(c, parent.getOrDefault(c, 0) + 1); // Acquiring characters till
                if(parent.getOrDefault(c, 0) <= child.getOrDefault(c, 0)) // match count is equal
                    match++;

                f1 = true;
            }
            while(left < right && match == t.length()){
                String potstring = s.substring(left + 1, right + 1);
                if(window.length() == 0 || window.length() > potstring.length())
                    window = potstring; //Calculating length of window

                    left++;
                    char c = s.charAt(left);
                    parent.put(c, parent.getOrDefault(c, 0) - 1);
                    if(parent.get(c) == 0) //Releasing characters by
                        parent.remove(c); //left pointer for finding smallest window

                    if(parent.getOrDefault(c, 0) < child.getOrDefault(c, 0))
                        match--;

                 f2 = true;
            }

            if(f1 == false && f2 == false)
                break;
        }

        return window;
    }
}