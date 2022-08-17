var evaluate = function(s, knowledge) {
    // key => value hash map can be directly constructed using the Map constructor
    const map = new Map(knowledge);
    
	// since bracket pairs can't be nested we can use a RegExp to capture keys and replace using a map constructed in the line above
	return s.replace(/\(([a-z]+)\)/g, (_, p1) => map.get(p1) ?? "?");
};

