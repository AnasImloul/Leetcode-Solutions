// Runtime: 3 ms (Top 83.72%) | Memory: 42.5 MB (Top 62.02%)
class Solution {
    public String toGoatLatin(String sentence) {
        StringBuffer sb = new StringBuffer();
        StringBuffer temp = new StringBuffer("a"); // temporary stringbuffer

        for(String str : sentence.split(" ")) {
            if(beginsWithConsonant(str)) {
                sb.append(str.substring(1)); // removing the first letter
                sb.append(str.charAt(0)); // appending it to the end
            } else {
                sb.append(str);
            }

            sb.append("ma"); // appending "ma" to the end of the word (common operation)
            sb.append(temp); // adding one letter 'a' to the end of each word

            // the first word gets "a" added to the end,
            // the second word gets "aa" added to the end,
            // and so on.
            temp.append("a"); // increasing the a's for every word
            sb.append(" "); // to put space between words
        }

        return sb.toString().trim(); // using trim() to remove the one extra space from the end of string.
    }

    public boolean beginsWithConsonant(String str) {
        return "aeiou".indexOf(str.toLowerCase().charAt(0)) == -1;
    }
}