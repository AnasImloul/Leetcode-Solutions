var Solution = function(w) {
    this.w = [];
    this.total = w.reduce((collector, el)=>collector+el,0)
    let start = 0
    for (const el of w){
        this.w.push([start, start+el])
        start = start+el 
    }
};

/**
 * @return {number}
 */
Solution.prototype.pickIndex = function() {
    const rand = Math.floor(Math.random()*this.total)
    for (let i = 0; i < this.w.length ; i++){
        const pair = this.w[i];
        if (pair[0] <= rand && rand < pair[1]){
            return i;
        }
    }
    
};
