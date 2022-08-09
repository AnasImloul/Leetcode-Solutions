var corpFlightBookings = function(bookings, n) {
    
    // +1 as dummy guard on the tail, which allow us not to check right boundary every time
    let unitStep = Array(n+1).fill(0);
    
    for(const [first, last, seatVector ] of bookings ){
        
        // -1 because booking flight is 1-indexed, given by description
        let [left, right] = [first-1, last-1];
        
        unitStep[ left ] += seatVector;
        unitStep[ right+1 ] -= seatVector;
    }
    
    // Reconstruct booking as drawing combination of retangle signal, built with unit step impulse
    for( let i = 1; i < unitStep.length ; i++ ){
        unitStep[ i ] += unitStep[ i-1 ];
    }
    
    
    // last one is dummy guard on the tail, no need to return
    return unitStep.slice(0, n);
};
