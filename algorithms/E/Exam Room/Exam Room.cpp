class ExamRoom {
public:
    set<int> s;  // ordered set
    int num;
    ExamRoom(int n) {
        num=n;    // total seats
    }
    
    int seat() {
        if(s.size()==0) { s.insert(0); return 0;}     // if size is zero place at seat 0
        auto itr = s.begin();
        if(s.size()==1) {                                      // if size==1 -> check if its closer to 0 or last seat (num-1) 
            if(*itr > num-1-(*itr)){ s.insert(0); return 0; }
              else{  s.insert(num-1); return num-1;}
        }
        int mx=-1;     // for max gap
        int l=0;          // for left index of the student to max gap.
        
        if(s.find(0)==s.end()){mx = (*itr); l=-mx;}    // if 0 is not seated -> check gap with 0 and starting seat.
		
		// Iterate the set to calculate gaps 
        for(int i=0;i<s.size()-1;i++)
        {
           int a=*itr;    // seat number  for 1st element 
           itr++;
           int b = *itr;   // seat number of next element in the set
		   
		   // check the gap and update
           if(mx<(b-a)/2){
               mx=(b-a)/2;
               l=a;
           }
        }
        if(s.find(num-1)==s.end()) {   // if last seat is vacant -> check gap with last filled seat and (num-1)
           if(mx< num-1-(*itr)) {
               mx = (num-1-(*itr));
               l=*itr;
           }
        }
        s.insert(l+mx);   // place the student at l+mx
        return l+mx;
        
        
    }
    
    void leave(int p) {
	// remove student from set
        s.erase(p);
    }
};
