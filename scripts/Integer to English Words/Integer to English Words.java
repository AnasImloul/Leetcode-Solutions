class Solution {
    
    private static final int[] INT_NUMBERS = {
            1_000_000_000, 1_000_000, 1000, 100, 90, 80, 70, 60, 50, 40, 30, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    private static final String[] STRING_NUMBERS = {
            "Billion", "Million", "Thousand", "Hundred", "Ninety", "Eighty", "Seventy", "Sixty", "Fifty", "Forty", "Thirty", "Twenty",
            "Nineteen", "Eighteen", "Seventeen", "Sixteen", "Fifteen", "Fourteen", "Thirteen", "Twelve", "Eleven", "Ten",
            "Nine", "Eight", "Seven", "Six", "Five", "Four", "Three", "Two", "One"};

    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        return numberToWordsHelper(num).toString();
    }

    private StringBuilder numberToWordsHelper(int num) {
        StringBuilder sb = new StringBuilder();
        if (num == 0) return sb;
        for (int i = 0; i < INT_NUMBERS.length; i++) {
            if (num >= INT_NUMBERS[i]) {
                if (num >= 100) {
                    sb.append(numberToWordsHelper(num / INT_NUMBERS[i]).append(" "));
                }

                sb.append(STRING_NUMBERS[i]).append(" ").append(numberToWordsHelper(num % INT_NUMBERS[i]));
                break;
            }
        }
        return sb.charAt(sb.length() - 1) == ' ' ? sb.deleteCharAt(sb.length() - 1) : sb; // trim
    }
    
}

