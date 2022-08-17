/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {number[]}
 */
var findOrder = function(numCourses, prerequisites) {
    let visiting = new Set();
    const visited = new Set();
    const adjList = new Map();
    const result = [];
    
	// Generate scaffold of adjacency list
	// initialized with no prereqs
    for (let i = 0; i < numCourses; i++) {
        adjList.set(i, []);
    }
    
	// Fill adjacency list with course prereqs
	// Key is the course
	// Value is any course prereqs
    for (const item of prerequisites) {
        const [course, prereq] = item;
        adjList.get(course).push(prereq);
    }
    
    const dfs = (node) => {
	    // We've already traversed down this path before
		// and determined that it isn't cyclical
        if (visited.has(node)) return true;
		
		// Visiting keeps track of what we've seen
		// during this current traversal and determines
		// if we have a cycle.
        if (visiting.has(node)) return false;
  
		// Mark this node as part of the current traversal
        visiting.add(node);
        
		// Get all adjacent nodes to traverse
		// traverse them in a loop looking for cycles
        const children = adjList.get(node);
        for (const child of children) {
            if (!dfs(child)) return false;
        }
		
		// Ensures we don't re-traverse already traversed nodes since
		// we've already determined they contain no cycles.
        visited.add(node);
		
		// Add this node to the result stack to return at the end
        result.push(node);
        return true;
    }
    
    for (const node of adjList.keys()) {
        if(!dfs(node)) return [];
    }
    
    return result;
};