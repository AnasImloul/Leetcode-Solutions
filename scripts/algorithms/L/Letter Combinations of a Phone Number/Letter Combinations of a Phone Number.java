class Solution {
    String[] num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    public List<String> letterCombinations(String digits) {
        List<String> ll = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        if (digits.length() != 0) {
            combination(digits.toCharArray(), ll, sb, 0);
        }
        return ll;
    }
    public void combination(char[] digits, List<String> ll, StringBuilder sb, int idx) {
        
        if (sb.length() == digits.length) {
            ll.add(sb.toString());
            return;
        }
        
        String grp = num[digits[idx] - 48];
        for (int i = 0; i < grp.length(); i++) {
            sb.append(grp.charAt(i));
            combination(digits, ll, sb, idx + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
        
    }
}
