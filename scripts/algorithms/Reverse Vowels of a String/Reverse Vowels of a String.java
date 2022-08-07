class Solution {
    public String reverseVowels(String s) {
        Set<Character> set = new HashSet<>();
        set.add('a');
        set.add('e');
        set.add('i');
        set.add('o');
        set.add('u');
        set.add('A');
        set.add('E');
        set.add('I');
        set.add('O');
        set.add('U');
        
        StringBuilder str = new StringBuilder(s);
        int left = 0, right = str.length() - 1;
        while (left < right) {
            if (!set.contains(str.charAt(left))) {
                left++;
            }
            if (!set.contains(str.charAt(right))) {
                right--;
            }
            if (set.contains(str.charAt(left)) && set.contains(s.charAt(right))) {
                char temp = str.charAt(left);
                str.setCharAt(left++, str.charAt(right));
                str.setCharAt(right--, temp);
            }
        }
        return str.toString();
    }
}
