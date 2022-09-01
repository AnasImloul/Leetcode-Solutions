// Runtime: 1 ms (Top 87.54%) | Memory: 42 MB (Top 80.66%)
class Solution {
    public List<String> removeComments(String[] source) {
        List<String> al = new ArrayList<>();

        // For building the required line of code as a string
        StringBuilder ans = new StringBuilder();

        // Whether multi-line comment is still open on the current line
        boolean multiLine = false;

        for(String string : source) {
            // To check for single line comment
            boolean singleLine = false;

            int i = 0;
            while(i < string.length() - 1) {
                // Case 1: Whether the current line is a part of previously opened multi-line comment block ("/*") OR
                // Whether a multi-line comment opening is found on the current index
                if(multiLine || (string.charAt(i) == '/' && string.charAt(i + 1) == '*')) {

                    // Edge case: If a new multi-line comment opening is found increment i by 2 for a case like "/*/"
                    if(!multiLine) i += 2;

                    // Traverse the current line until the closing charcters for multi-line comment are found
                    while(i < string.length() - 1 && (string.charAt(i) != '*' || string.charAt(i + 1) != '/')) {
                        i++;
                    }

                    // If closing characters are not found, it means the comment continues on the next line
                    if(i == string.length() - 1) {
                        multiLine = true;

                    // Else point the control on the next character, ignoring the discovered comment
                    } else {
                        multiLine = false; // Comment closed
                        i += 2;
                    }

                // Case 2: For Single Line comments, ignore the entire line after the current character
                } else if(string.charAt(i) == '/' && string.charAt(i + 1) == '/') {
                    singleLine = true;
                    break;

                // Append any normal character to the stringbuilder
                } else {
                    ans.append(string.charAt(i++));
                }
            }

            // As the loop ran till the last second character, the last one needs to be acknowledged only if there are no comment blocks
            if(i < string.length() && !multiLine && !singleLine) ans.append(string.charAt(i));

            // If the stringbuilder atleast has one character and it is not a part of any multi-line comment, add it to the answer list
            if(ans.length() > 0 && !multiLine) al.add(ans.toString());

            // If the answer list gets an addition, redeclare the stringbuilder object for a new line
            // If there was a multi-line comment active, then the strings before and after the entire multi-line comment block are considered as a single string
            if(!multiLine) ans = new StringBuilder();
        }

        return al;
    }
    }