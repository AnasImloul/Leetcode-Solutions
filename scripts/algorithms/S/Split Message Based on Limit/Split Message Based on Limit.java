// Runtime: 36 ms (Top 81.5%) | Memory: 51.34 MB (Top 53.0%)

class Solution {
    public String[] splitMessage(String message, int limit) {
        int[] stgTable = {
                (limit - 5) * 9,
                (limit - 6) * 9 + (limit - 7) * 90,
                (limit - 7) * 9 + (limit - 8) * 90 + (limit - 9) * 900,
                (limit - 8) * 9 + (limit - 9) * 90 + (limit - 10) * 900 + (limit - 11) * 9000,
        };
        int l = message.length(), stg = 0;
        while (stg < stgTable.length) {
            if (stgTable[stg] >= l) break;
            stg++;
        }
        if (stg == stgTable.length) return new String[0];
        ArrayList<String> list = new ArrayList<>();
        int idx = 1, strIdx = 0;
        for (int i = 0; i <= stg; i++) {
            int size = limit - 5 - stg - i;
            for (int j = 0; j < 9 * Math.pow(10, i) && strIdx < message.length(); j++) {
                list.add(message.substring(strIdx, Math.min(message.length(), strIdx + size)) + "<" + idx);
                strIdx += size;
                idx++;
            }
        }
        String[] res = list.toArray(new String[]{});
        for (int i = 0; i < res.length; i++)
            res[i] = res[i] + "/" + (idx - 1) + ">";
        return res;
    }
}