/**
 * @param {string} rings
 * @return {number}
 */
var countPoints = function(rings) {
    let rods = Array(10).fill("");
    for(let i = 0; i < rings.length; i += 2){
        if(!(rods[rings[i+1]].includes(rings[i]))) rods[rings[i+1]] += rings[i]
    }
    return rods.filter(rod => rod.length > 2).length
};