class Solution {
    public String convert(String s, int numRows) {
        if (numRows==1)return s;
        StringBuilder builder = new StringBuilder();
        for (int i=1;i<=numRows;i++){
            int ind = i-1;
            boolean up = true;
            while (ind < s.length()){
                builder.append(s.charAt(ind));
                if (i==1){
                    ind += 2*(numRows-i);
                } else if (i==numRows){
                    ind += 2*(i-1);
                } else {
                    ind += up ? 2*(numRows-i) : 2*(i-1);
                    up=!up;
                }
            }
        }
        return builder.toString();
    }
}
