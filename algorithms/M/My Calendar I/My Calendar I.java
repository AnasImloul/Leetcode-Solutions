class MyCalendar {
    public int start;
    public int end;
    Set<MyCalendar> calender = new HashSet<MyCalendar>();
    public MyCalendar(int start,int end){
            this.start = start;
            this.end = end;
    }
     public MyCalendar()  {  
     } 
     @Override
    public boolean equals(Object o){
         MyCalendar n = (MyCalendar) o;
         if( n.start >= this.end){
                return false;
            }
            else if(n.end <= this.start){
                return  false;
            }
            else 
              return  true;
    }
     public int hashCode() {
      return 1;
    }

    public boolean book(int start, int end) {
        return calender.add(new MyCalendar(start,end));
    }
	}
