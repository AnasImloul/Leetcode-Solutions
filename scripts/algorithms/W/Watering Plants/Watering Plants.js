var wateringPlants = function(plants, capacity) {
    var cap = capacity;
    var steps = 0;
    for(let i = 0; i < plants.length;i++){
        if(cap >= plants[i]){
            steps = steps + 1;
        }else{
            cap = capacity;
            steps = steps + (2 *i + 1);
        }
        cap = cap - plants[i];
    }
    return steps;
};
