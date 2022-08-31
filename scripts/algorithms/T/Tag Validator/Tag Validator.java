// Runtime: 3 ms (Top 66.89%) | Memory: 41.9 MB (Top 78.38%)
class Solution {
    // for the ease to check CDATA starting tag
    private static final char[] CDATA_TAG = {'[','C','D','A','T','A','['};
    public boolean isValid(String code) {
        // make sure it is possible to have a start tag and an end tag
        if (!code.startsWith("<") || !code.endsWith(">")) {
            return false;
        }
        Deque<String> stack = new ArrayDeque<>();
        for (int i = 0; i < code.length(); ++i) {
            char ch = code.charAt(i);
            // if it is a special tag
            if (ch == '<') {
                if (i == code.length() - 1) {
                    return false;
                }
                ch = code.charAt(++i);
                // is end tag
                if (ch == '/') {
                    // we should have a start tag to match the end tag
                    if (stack.isEmpty()) {
                        return false;
                    }
                    // get the end tag
                    StringBuilder sb = new StringBuilder();
                    // build tag and move i to the > for the next round
                    i = buildTag(code, i + 1, sb);
                    // if tag is unmatch, return false
                    if (!stack.pop().equals(sb.toString())) {
                        return false;
                    }
                    // if no start tag left and we are not at the end. The rest content is not enclosed. -> false
                    if (stack.isEmpty() && i < code.length() - 1) {
                        return false;
                    }
                } else if (ch == '!') { // is CDATA tag
                    // check if CDATA is encoded in a tag
                    if (stack.isEmpty()) {
                        return false;
                    }
                    // check CDATA and move i to the end of ]]> for the next round
                    i = validAndMoveCDATA(code, i + 1);
                    // the above function return -1 if CDATA is not valid
                    if (i < 0) {
                        return false;
                    }
                } else { // start tag
                    // TAG_NAME should not empty
                    if (ch == '>') {
                        return false;
                    }
                    StringBuilder sb = new StringBuilder();
                    i = buildTag(code, i , sb);
                    // TAG_NAME should less than 9
                    if (sb.isEmpty() || sb.length() > 9) {
                        return false;
                    }
                    stack.push(sb.toString());
                }
            }
        }
        return stack.isEmpty();
    }

    private int buildTag(String code, int start, StringBuilder sb) {
        int i = start;
        // we only go to 10 because the max length is 9
        for (; i < start + 10 && i < code.length(); ++i) {
            char ch = code.charAt(i);
            // find the end;
            if (ch == '>') {
                break;
            }
            // TAG_NAME should be in uppercase only
            if (!Character.isUpperCase(ch)) {
                // clear the string builder for invalid TAG_NAME
                sb.setLength(0);
                break;
            }
            sb.append(ch);
        }
        return i;
    }

    private int validAndMoveCDATA(String code, int start) {
        // the length of [CDATA[]]> is 10 we need at least 10 characters left
        if (code.length() - start < 10) {
            return -1;
        }
        // check the start part
        int i = start;
        for (int j = 0; j < CDATA_TAG.length; ++j) {
            char ch = code.charAt(i++);
            if (ch != CDATA_TAG[j]) {
                return -1;
            }
        }
        // keep the last two characters for identifying the end
        char prev0 = '\0';
        char prev1 = '\0';

        for (; i < code.length(); ++i) {
            char ch = code.charAt(i);
            if (ch == '>' && prev1 == ']' && prev0 == ']') {
                return i;
            }
            prev0 = prev1;
            prev1 = ch;
        }
        // no end found
        return -1;
    }
}