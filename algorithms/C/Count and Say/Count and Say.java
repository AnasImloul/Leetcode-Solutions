class Solution {
    public String countSay(int n, String[] mapper) {
        if (n == 1) return mapper[1];
        else {
            String say = "";
            if (mapper[n-1] != null) say += mapper[n-1];
            else say += countSay(n-1, mapper);
            String count = "";
            int cache = Integer.parseInt(say.substring(0, 1));
            int cntr = 1;
            if (say.length() < 2) {
                count += "1" + Integer.toString(cache);
            } else {
                for(int i=1;i<say.length();i++) {
                    if (cache == Integer.parseInt(say.substring(i, i+1))) {
                        cntr++;
                        if (i == say.length() - 1) {
                            count += Integer.toString(cntr) + Integer.toString(cache);
                            cntr = 1;
                        }
                    } else {
                        count += Integer.toString(cntr) + Integer.toString(cache);
                        if (i < say.length() - 1) {
                            cache = Integer.parseInt(say.substring(i, i+1));
                            cntr = 1;
                        } else if (i == say.length() - 1) {
                            count += "1" + say.substring(i, i+1);
                        }
                    }
                }
            }
            mapper[n] = count;
            return mapper[n];
        }
    }
    public String countAndSay(int n) {
        String mapper[] = new String[n+1];
        mapper[1] = "1";
        return countSay(n, mapper);
    }
}
