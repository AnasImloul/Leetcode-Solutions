// Runtime: 1 ms (Top 91.49%) | Memory: 42.3 MB (Top 21.28%)
class Solution {
    public int numberOfRounds(String loginTime, String logoutTime) {
        String[] arr1 = loginTime.split(":");
        String[] arr2 = logoutTime.split(":");

        int time1 = Integer.parseInt(arr1[0])*60 + Integer.parseInt(arr1[1]);
        int time2 = Integer.parseInt(arr2[0])*60 + Integer.parseInt(arr2[1]);

        if(time1 > time2) time2 = time2 + 24*60;
        if(time1%15 != 0) time1 = time1 + 15-time1%15;

        return (time2 - time1)/15;
    }
}