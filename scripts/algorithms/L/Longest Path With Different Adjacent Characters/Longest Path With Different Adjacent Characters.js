var longestPath = function(parent, s) {
  const adjList = parent.reduce((adjList, parent, node) => {
    if (parent < 0) return adjList;
    adjList[parent].push(node);
    return adjList;
  }, new Array(parent.length).fill(0).map(() => []));
  
  let longest = 1;
  
  const getLongest = (node) => {
    let maxChild1 = 0;
    let maxChild2 = 0;
    
    adjList[node].forEach((child) => {
      const childLength = getLongest(child);
    
	  // child letter matches our node, so we can't use it
      if (s[child] === s[node]) return;
      
	  // compare and update the longest two child paths
      if (childLength > maxChild1) {
        maxChild2 = maxChild1;
        maxChild1 = childLength;
      } else if (childLength > maxChild2) {
        maxChild2 = childLength;
      }
    });
    
	// longest loop
    longest = Math.max(longest, maxChild1 + maxChild2 + 1);
    
	// return longest path up the tree
    return 1 + maxChild1;
  }
  
  getLongest(0);
  
  return longest;
};
