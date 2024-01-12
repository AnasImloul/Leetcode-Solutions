// Runtime: 24 ms (Top 72.47%) | Memory: 45.70 MB (Top 34.84%)

class Solution {
    public String arrangeWords(String text) {
        text = text.replace(text.charAt(0)+"", (char)(text.charAt(0)+32)+"");

        String[] arr = text.split(" ");
        Arrays.sort(arr, new Comparator<String>(){
            public int compare(String s1, String s2){
                return Integer.compare(s1.length(), s2.length());
            }
        });

        StringBuilder str = new StringBuilder(arr[0]);

        for(int i = 1; i < arr.length; i++)
            str.append(" "+arr[i]);

        text = (char)(str.charAt(0)-32)+str.substring(1, str.length());

        return text;
    }
}
// UP-VOTE IF HELPFUL
