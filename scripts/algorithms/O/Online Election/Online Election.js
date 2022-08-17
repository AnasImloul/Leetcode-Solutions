var TopVotedCandidate = function(persons, times) {
    this.times = times;
    this.len = times.length;
    this.votes = new Array(this.len).fill(0);
    
    let max = 0; // max votes received by any single candidate so far.
    let leader = -1l;
    
    this.leaders = persons.map((person, i) => {
        this.votes[person]++;
        
        if (this.votes[person] >= max) {
            max = this.votes[person];
            leader = person;
        }
        
        return leader;
    });
    
};

TopVotedCandidate.prototype.q = function(t) {
    let left = 0;
    let right = this.len - 1;
    
    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);
        
        if (this.times[mid] === t) return this.leaders[mid];
        else if (this.times[mid] < t) left = mid + 1;
        else right = mid - 1;
    }
	
    return this.leaders[right];
};
