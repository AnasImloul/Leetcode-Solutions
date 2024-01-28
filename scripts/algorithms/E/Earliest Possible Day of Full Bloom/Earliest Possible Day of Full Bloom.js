// Runtime: 176 ms (Top 92.31%) | Memory: 75.70 MB (Top 73.08%)

/**
 * @param {number[]} plantTime
 * @param {number[]} growTime
 * @return {number}
 */

var earliestFullBloom = function(plantTime, growTime) {
    // create array of plant indices to identify plants after sorting 
    const plants = plantTime.map((v, i) => i)
    // sort plants by longest grow time
    const sortedByGrowTime = plants.sort((a,b) => growTime[b] - growTime[a])
    
    // iterate over plants, planting those with longest grow time first
    // track the sum of plantTimes
    // Max of current plantTime sum + growTime[i] for all plants will be earliest bloom day
    let plantTimeSum =0, fullBloomDay = -1
    for(const plant of sortedByGrowTime) {
        plantTimeSum += plantTime[plant]
        fullBloomDay = Math.max(fullBloomDay, plantTimeSum + growTime[plant])
    }
    return fullBloomDay
};
