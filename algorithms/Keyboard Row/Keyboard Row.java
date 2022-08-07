class Solution {
    public String[] findWords(String[] words) {
        String row1 = "qwertyuiop";
        String row2 = "asdfghjkl";
        String row3 = "zxcvbnm";
        String res = "";
        for(int i=0; i<words.length; i++) {
            int sum1 = 0;
            int sum2 = 0;
            int sum3 = 0;
            for(int j=0; j<words[i].length(); j++) {
                if(row1.contains("" + words[i].toLowerCase().charAt(j))) {
                    sum1++;
                }
                else if(row2.contains("" + words[i].toLowerCase().charAt(j))) {
                    sum2++;
                }
                else if(row3.contains("" + words[i].toLowerCase().charAt(j))) {
                    sum3++;
                }
            }
            if(words[i].length()==sum1) {
                res += i;
            }
            else if(words[i].length()==sum2) {
            	res += i;
            }
            else if(words[i].length()==sum3) {
            	res += i;
            }
        }
		String[] resArr = new String[res.length()];
		for(int i=0; i<resArr.length; i++) {
			resArr[i] = words[Integer.parseInt("" + res.charAt(i))];
			System.out.println(resArr[i]);
		}
        return resArr;
    }
}
