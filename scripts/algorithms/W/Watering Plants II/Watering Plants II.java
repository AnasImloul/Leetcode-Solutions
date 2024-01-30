// Runtime: 4 ms (Top 96.18%) | Memory: 57.70 MB (Top 65.65%)

class Solution {
    public int minimumRefill(int[] p, int ca, int cb) {                
	
        int refill= 0,oca =  ca, ocb =  cb;// let save our  orginal capacity    , needed to refill can again
        int i=0, j = p.length-1; // starting both end 
        
        while(i<=j){
		
             if(i==j){// mean both at same position
                if(ca>=cb){
                   if(p[i]>ca){
                        refill++;
                    }                         
                }
                 else{                                      
                      if(p[j]>cb){
                        refill++;                        
                    }                     
                 }
				 // no more plant left for watering so break loop 
                 break; 
            }
                       
            // first check if they have sufficient amount of water 
            // if not then refill it with orginal capacity                 
			
            if(p[i]>ca){
                refill++;
                ca =  oca;
            }            
            if(p[j]>cb){
                refill++;
                cb=  ocb;
            }
            
			// decrease consumed water 
            ca-=p[i] ;                                  
            cb-=p[j]; 
			
			// move both 
			i++;           
            j--;			                                                
        }
        return refill;                
    }
}
