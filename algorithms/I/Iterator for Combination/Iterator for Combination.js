/**
 * @param {string} characters
 * @param {number} combinationLength
 */
var CombinationIterator = function(characters, combinationLength) {
    
    this.combinations = [];
    
    const buildAllCombination = (curString, masterString) => {
        if(curString.length == combinationLength ){
            this.combinations.push(curString);
        }
        if(curString.length > combinationLength ) return ;
        for(let g=0; g<masterString.length; g++){
            buildAllCombination(curString + masterString[g], masterString.slice(g+1));
        }
        
    }
    //lets sort it first
    characters = characters.split('').sort( (a, b) => a-b );
    buildAllCombination('', characters); // lets build the combinations;
    this.counter = 0;
    
    
};

/**
 * @return {string}
 */
CombinationIterator.prototype.next = function() {
  
    let res =  this.combinations[this.counter];
    this.counter++;
    return res;
    
    
};

/**
 * @return {boolean}
 */
CombinationIterator.prototype.hasNext = function() {
    
    return this.counter < this.combinations.length;
};

/** 
 * Your CombinationIterator object will be instantiated and called as such:
 * var obj = new CombinationIterator(characters, combinationLength)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
