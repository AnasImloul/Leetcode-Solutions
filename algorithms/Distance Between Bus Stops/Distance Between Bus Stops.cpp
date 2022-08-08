		 Going from Start to Destination and then from Destination to start as 
		 the bus stops are connected in a circle then returning the minimum of both trips.
		 TC : O(N)
		 SC: O(1)
		 
	 class Solution {
	 public:
	 int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
	 int d1=0,d2=0;
	 int newdestination=start;
	 int n=distance.size();
	 while(start!=destination){
			 d1+=distance[start];
			 start=(start+1)%n;}
	 while(start!=newdestination) {
			 d2+=distance[start]; 
			 start=(start+1)%n;}
    
    return min(d1,d2);
    
}
