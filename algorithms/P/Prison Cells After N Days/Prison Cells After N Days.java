class Solution {
    public int[] prisonAfterNDays(int[] cells, int n) {
        // # Since we have 6 cells moving cells (two wil remain unchaged at anytime) 
        // # the cycle will restart after 14 iteration
        // # 1- The number of days if smaller than 14 -> you brute force O(13)
        // # 2- The number is bigger than 14
        // #                       - You do a first round of 14 iteration
        // #                       - Than you do a second round of n%14 iteration
        // #                       ===> O(27)
        
        n = n % 14 == 0 ? 14 : n%14;
        int temp[] = new int[cells.length];
        
        while(n-- > 0)
        {
            for(int i=1; i <cells.length- 1; i++)
            {
              temp[i] = cells[i-1] == cells[i+1]? 1: 0;
            }
            cells = temp.clone();
        }

        return cells;
    }
}
