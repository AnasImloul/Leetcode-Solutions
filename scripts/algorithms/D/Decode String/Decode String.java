// Runtime: 1 ms (Top 88.88%) | Memory: 41.8 MB (Top 72.85%)
class Solution {
    public String decodeString(String s) {

        int bb = s.indexOf('['); // location of beginning bracket
        int nbb = s.indexOf('[', bb + 1); // location of next beginning bracket
        int eb = s.indexOf(']'); // location of ending bracket

        int n = 0; // number of times to repeat
        int nl = 1; // number of digits for n
        char nd; // next digit

        String insert = ""; // repeated string
        String end = ""; // remainder of string after repeated portion

        while (bb != -1) { // while the string contains a beginning bracket

            while (nbb < eb && nbb > bb) { // while the next beginning bracket is before the ending bracket
                bb = nbb; // update location of beginning bracket
                nbb = s.indexOf('[', bb + 1); // update location of next beginning bracket
            }

            nl = 1; // reset length of n
            while (bb - nl >= 0) { // while there are characters in front of the beginning bracket
                nd = s.charAt(bb - nl); // next digit
                if (nd <= '9' && nd >= '0') { // if next digit is an integer
                    n += (int)(nd - '0') * Math.pow(10, nl - 1); // update value of n
                    nl++; // increment length of n
                }
                else break; // not an integer
            }

            insert = s.substring(bb + 1, eb); // set repeated string
            end = s.substring(eb + 1); // set remainder of string
            s = s.substring(0, bb - nl + 1); // remove everything after the digits

            while (n > 0) {
                s += insert; // add repeated string n times
                n--;
            }
            s += end; // add remainder of string

            bb = s.indexOf('['); // new location of beginning bracket
            nbb = s.indexOf('[', bb + 1); // new location of next beginning bracket
            eb = s.indexOf(']'); // new location of ending bracket
        }
        return s;
    }
}