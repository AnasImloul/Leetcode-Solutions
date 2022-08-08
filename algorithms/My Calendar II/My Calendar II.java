class MyCalendarTwo {
    private List<int[]> bookings;
    private List<int[]> doubleBookings;
    
    public MyCalendarTwo() {
        bookings = new ArrayList<>();
        doubleBookings = new ArrayList<>();
    }
    
 
    public boolean book(int start, int end) {
        for(int[] b : doubleBookings)
        {
		//condition to check for the overlaping
            if(start < b[1] && end > b[0])
                return false;
        }
        
        for(int[] b : bookings)
        {
            if(start < b[1] && end > b[0]) {
                doubleBookings.add(new int[] {Math.max(start, b[0]), Math.min(end, b[1])});
            }
        }
        bookings.add(new int[]{start, end});
        return true;
    }
}
