class Solution {
    public String dayOfTheWeek(int day, int month, int year) {
        String[] week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        year--;
        int total = (year/4)*366+(year-year/4)*365;
        int[] months = {31,28,31,30,31,30,31,31,30,31,30,31};
        year++;
        if(year%4==0 && year!=2100){
            months[1]++;
        }
        for(int i=0;i<month-1;i++){
            total+= months[i];
        }
        total +=day;
        // for(int i:months){
        //     System.out.print(i+" ");
        // }
        // System.out.println();
        return week[(total-1)%7];
        
    }
}