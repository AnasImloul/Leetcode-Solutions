// Runtime: 1 ms (Top 96.0%) | Memory: 42.30 MB (Top 49.23%)

class Solution {
    public String[] divideString(String s, int k, char fill) {
        //the size of result array
        String[] r = new String[(int) Math.ceil((s.length() * 1.0) / k)];
        int idx;
        //if the last one needs to be filled, then I do it
        if (s.length() % k != 0) {
            idx = s.length() - (s.length() % k);
            StringBuilder sb = new StringBuilder();
            sb.append(s.substring(idx));
            for (int i = sb.length(); i < k; i++) {
                sb.append(fill);
            }
            r[r.length - 1] = sb.toString();
        } else {
            //no need to fill the last, 
            //that's why idx is equal to s length
            idx = s.length();
        }
        for (int i = 0; i < idx; i+=k) {
            r[i / k] = s.substring(i, i + k);
        }
        
        return r;
    }
}
