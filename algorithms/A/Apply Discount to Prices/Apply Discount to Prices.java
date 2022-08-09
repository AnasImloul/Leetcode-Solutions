class Solution {

    public String discountPrices(String sentence, int discount) {
        String x[] = sentence.split(" ");
        StringBuilder sb = new StringBuilder();
        for (String s : x) {
            if (isPrice(s)) sb.append(calc(Double.parseDouble(s.substring(1)), discount) + " "); 
            else sb.append(s + " ");
        }
        sb.deleteCharAt(sb.length() - 1);
        return sb.toString();
    }

    boolean isPrice(String s) {
        return s.startsWith("$") && s.substring(1).matches("\\d+");
    }

    String calc(double num, double discount) {
        double ans = num - (double) ((double) num * discount / 100.00);
        return "$" + String.format("%.2f", ans);
    }
}
