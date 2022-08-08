/**
 * @param {number[][]} routes
 * @param {number} source
 * @param {number} target
 * @return {number}
 */
var numBusesToDestination = function(routes, source, target) {
  // This map will hold an adjacency map of all the routes each stop can go to
  let stopRoutes = new Map();
  
  // Initialize adjacency map - for each route
  for (let route = 0; route < routes.length; route++) {
    // Look at all of the route's stops
    for (let stop of routes[route]) {
      // If we haven't added this stop yet then create a new entry for it
      if (!stopRoutes.has(stop)) stopRoutes.set(stop, new Set());
      // Add the current route as a possible route this stop can go to
      stopRoutes.get(stop).add(route);
    }
  }
  
  // This queue will contain all of the visited stops AND the number of buses it took to get to that stop
  let stopsToVisit = new Queue();
  // We start at the source and 0 buses to get there
  stopsToVisit.enqueue([source, 0]);
  
  // This set will contain all of the stops we've already visited
  let visitedStops = new Set();
  visitedStops.add(source);
  
  // This set will contain all of the routes we've visited
  let visitedRoutes = new Array(routes.length);
  
  // While there are more stops to visit
  while(!stopsToVisit.isEmpty()) {
    // Get the queued stop and number of buses it took to get there
    let stop = stopsToVisit.front()[0], bus = stopsToVisit.front()[1];
    stopsToVisit.dequeue();
    
    // If the stop is our target then we return the number of buses it took to get here
    if (stop === target) return bus;
    
    // Loop over all the routes this stop can go to
    for (let route of stopRoutes.get(stop)) {
      // If we've already visited this route then don't do it again
      if (visitedRoutes[route]) continue;
      
      // Loop over all of the stops in this route
      for (let stop of routes[route]) {
        // If we haven't visited this stop before
        if (!visitedStops.has(stop)) {
          // Add it to the stops we've visited
          visitedStops.add(stop);
          // Add it to the queue of stops we need to visit adding 1 more bus stop to get to it
          stopsToVisit.enqueue([stop, bus + 1]);
        }
      }
      
      // Set the current route as visited
      visitedRoutes[route] = true;
    }
  }
  
  // If we never got to our target then return -1
  return -1;
};
