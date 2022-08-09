class Solution {
    public int superpalindromesInRange(String left, String right) {
        int ans = 9 >= Long.parseLong(left) && 9 <= Long.parseLong(right) ? 1 : 0;
  
        for (int dig = 1; dig < 10; dig++) {
            boolean isOdd = dig % 2 > 0 && dig != 1;
            int innerLen = (dig >> 1) - 1,
                innerLim = Math.max(1, (int)Math.pow(2, innerLen)),
                midPos = dig >> 1, midLim = isOdd ? 3 : 1;
            for (int edge = 1; edge < 3; edge++) {
                char[] pal = new char[dig];
                Arrays.fill(pal, '0');
                pal[0] = (char)(edge + 48);
                pal[dig-1] = (char)(edge + 48);
                if (edge == 2) {
                    innerLim = 1;
                    midLim = Math.min(midLim, 2);
                }
                for (int inner = 0; inner < innerLim; inner++) {
                    if (inner > 0) {
                        String innerStr = Integer.toString(inner, 2);
                        while (innerStr.length() < innerLen)
                            innerStr = "0" + innerStr;
                        for (int i = 0; i < innerLen; i++) {
                            pal[1+i] = innerStr.charAt(i);
                            pal[dig-2-i] = innerStr.charAt(i);
                        }
                    }
                    for (int mid = 0; mid < midLim; mid++) {
                        if (isOdd) pal[midPos] = (char)(mid + 48);
                        String palin = new String(pal);
                        long square = Long.parseLong(palin) * Long.parseLong(palin);
                        if (square > Long.parseLong(right)) return ans;
                        if (square >= Long.parseLong(left) && isPal(Long.toString(square))) ans++;
                    }
                }
            }
        }
        return ans;
    }
    
    private boolean isPal(String str) {
        for (int i = 0, j = str.length() - 1; i < j; i++, j--)
            if (str.charAt(i) != str.charAt(j)) return false;
        return true;
    }
}
