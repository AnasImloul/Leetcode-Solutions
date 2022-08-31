// Runtime: 19 ms (Top 41.17%) | Memory: 45.4 MB (Top 53.10%)

class Solution {
    public int numberOfSubstrings(String s) {
        int a = 0, b = 0, c = 0, count = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'a': ++a; break;
                case 'b': ++b; break;
                case 'c': ++c; break;
            }
            if (a > 0 && b > 0 && c > 0) {
                while (a > 0 && b > 0 && c > 0) {
                    char farLeft = s.charAt(i - a - b - c + 1);
                    switch (farLeft) {
                        case 'a': {
                            --a;
                            count += doCount(s, i);
                            break;
                        }
                        case 'b': {
                            --b;
                            count += doCount(s, i);
                            break;
                        }
                        case 'c': {
                            --c;
                            count += doCount(s, i);
                            break;
                        }
                    }
                }
            }
        }
        return count;
    }

    private int doCount(String s, int i) {
        int count = 0;
        int n = s.length() - i;
        if (n > 0) {
            count += n;
        }
        return count;
    }
}