var SeatManager = function(n) {
    
    this.min = 1
    this.n = n
    this.seat = []
    
};

SeatManager.prototype.reserve = function() {

    let res
	
    if( !this.seat[this.min] ){
        
        res = this.min
        this.min = this.n < this.min ? NaN : this.min + 1

    } else {
        
        res = this.min
        this.min = this.seat[this.min]
        
    }
    
    return res
};

SeatManager.prototype.unreserve = function(seatNumber) {
    
    if (this.min < seatNumber ) {
        
        let pre_inx = this.min 
        let next_inx = this.seat[this.min]
        
        while(next_inx < seatNumber){
            pre_inx = next_inx
            next_inx = this.seat[next_inx]
        }
        
        [ this.seat[pre_inx], this.seat[seatNumber] ] = [ seatNumber, this.seat[pre_inx] ]
        
    } else {
        
        [ this.seat[seatNumber], this.min ] = [ this.min, seatNumber ]
        
    }
};
