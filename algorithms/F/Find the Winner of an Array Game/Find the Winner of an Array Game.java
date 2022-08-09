class Solution {
    public int getWinner(int[] arr, int k) {
       
       int winner =arr[0];
        int count=0;
        for(int i=1;i<arr.length;i++)
        {
                if(winner>arr[i])
                    count++;
                else
                {
                    winner=arr[i];
                    count=1;
                }
            if(count==k)
                return winner;
        }
        return winner;
    }
}
