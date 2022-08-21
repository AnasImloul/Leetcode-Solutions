// Runtime: 32 ms (Top 59.76%) | Memory: 51.4 MB (Top 55.86%)

class Solution {

 public String getHappyString(int n, int k) {
        List<String> innerList = new ArrayList<>();
        getHappyStringUtil(n, k, new char[] { 'a', 'b', 'c' }, new StringBuilder(), innerList);
        if (innerList.size() < k)
            return "";
        return innerList.get(k - 1);
    }

    public void getHappyStringUtil(int n, int k, char[] letter, StringBuilder tempString, List<String> innerList) {
        // Base case
        if (tempString.length() == n) {
            innerList.add(tempString.toString());
            return;
        }

        // Recursive call
        for (int i = 0; i < 3; i++) {
            if (tempString.length() > 0 && tempString.charAt(tempString.length() - 1) == letter[i])
                continue;
            tempString.append(letter[i]);
            getHappyStringUtil(n, k, letter, tempString, innerList);
            tempString.deleteCharAt(tempString.length() - 1);
        }

    }
}