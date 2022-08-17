class Solution {
    public String abbreviateProduct(int left, int right) {
        int zero = 0;
        boolean mod = false;
        
        long val = 1L;
        for (int i = left; i <= right; i++) {
            val *= i;
            while (val % 10 == 0) {
                val /= 10;
                zero++;
            }
            if (val > 10_000_000_000L) {
                val %= 10_000_000_000L;
                mod = true;
            }
        }
        if (!mod) {
            return String.format("%de%d", val, zero);
        }
        long end = val % 100_000L;
        double s = 0.0;
        for (int i = left; i <= right; i++) {
            s += Math.log10(i);
        }
        s -= (int)s;
        double start = Math.pow(10.0, (s + 4));
        return String.format("%d...%05de%d", (int)start, end, zero);
    }
}
