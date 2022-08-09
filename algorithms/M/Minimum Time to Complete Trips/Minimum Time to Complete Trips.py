class Solution(object):
    def minimumTime(self, time, totalTrips):
        anstillnow=-1;
        left=1;
        right= 100000000000001;
        
        while(left<=right):
            mid= left+ (right-left)/2      #find mid point like this to avoid overflow
            
            curr_trips=0;
            
            for t in time:
                curr_trips+= mid/t
            
            if(curr_trips>=totalTrips):
                anstillnow=mid
                right=mid-1
            
            else:
                left=mid+1

        return anstillnow
