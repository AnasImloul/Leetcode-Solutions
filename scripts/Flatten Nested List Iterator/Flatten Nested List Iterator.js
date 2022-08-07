var NestedIterator = function(nestedList) {
    this.integers = []
    this.index = 0
    this.flatten(nestedList)
};
NestedIterator.prototype.hasNext = function() {
    return this.index < this.integers.length;
};

NestedIterator.prototype.next = function() {
    return this.integers[this.index++];
};

NestedIterator.prototype.flatten = function(list) {
    for(member of list){
        if(member.isInteger()){
            this.integers.push(member.getInteger())
        } else {
            this.flatten(member.getList())
        }
    }
};
