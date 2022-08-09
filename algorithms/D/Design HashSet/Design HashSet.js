var MyHashSet = function() {
  
    // Really you should just 
    // Make your own object, but instead
    // we have attached ourself to the 
    // `this` object which then becomes our hashmap.
    
    // What you should instead do is this:
    // this.hash_map = {}
    // And then update our following functions
};

MyHashSet.prototype.add = function(key) {
    
    // Constant Time
    // Linear Space | To the size of the input key
    // You can access objects using array notation

    this[key] = null;
};

MyHashSet.prototype.remove = function(key) {
    
    // Constant Time
    // Constant Space
    // You can access objects using array notation
    // Here we use the delete keyword.

    delete this[key]
};

MyHashSet.prototype.contains = function(key) {
    
    // Constant Time
    // Constant Space
    // This just asks if the property exists

    return this.hasOwnProperty(key)
};
