var isNStraightHand = function(hand, groupSize) {
    if(hand.length%groupSize!==0) return false;
	
    const map = new Map();
    hand.forEach(h=>{
        map.set(h,map.get(h)+1||1);
    });
    
	// sort based on the key in asc order
    const sortedMap = new Map([...map.entries()].sort((a,b)=>a[0]-b[0]));
    
    while(sortedMap.size){
	// getting the first key
        const firstKey = sortedMap.keys().next().value; 
        for(let i=firstKey;i<firstKey+groupSize;++i){
            if(!sortedMap.has(i)){
                return false
            }
            const freq = sortedMap.get(i);
            if(freq===1){
                sortedMap.delete(i)
            }else{
                sortedMap.set(i,sortedMap.get(i)-1);
            }
        }
    }
    return true;
};
