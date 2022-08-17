var minimumEffort = function(tasks) {
  let minimumStartingEnergy = 0;
  let currentEnergy = 0;
  
  tasks.sort((a, b) => (b[1] - b[0]) - (a[1] - a[0]) );
  
  for (let task of tasks) {
    if (task[1] > currentEnergy) {
      minimumStartingEnergy += (task[1] - currentEnergy);
      currentEnergy = task[1];
    }
    currentEnergy -= task[0];
  }
  
  return minimumStartingEnergy;
};
