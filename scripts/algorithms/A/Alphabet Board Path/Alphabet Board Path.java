// Runtime: 0 ms (Top 100.0%) | Memory: 40.07 MB (Top 98.6%)

class Solution {
    public String alphabetBoardPath(String target) {
        int x = 0, y = 0;
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < target.length(); i++){
            char ch = target.charAt(i);
            int x1 = (ch - 'a') / 5;
            int y1 = (ch - 'a') % 5;
            while(x1 < x)   {x--; sb.append('U');}
            while(y1 > y)   {y++; sb.append('R');}
            while(y1 < y)   {y--; sb.append('L');}
            while(x1 > x)   {x++; sb.append('D');}
            sb.append('!');
        }
        return sb.toString();
    }
}