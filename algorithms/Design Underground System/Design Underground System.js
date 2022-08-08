var UndergroundSystem = function() {
    this.checkInMap = {}
    this.tripMap = {}
};

/** 
 * @param {number} id 
 * @param {string} stationName 
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkIn = function(id, stationName, t) {
    this.checkInMap[id] = [stationName, t]
};

/** 
 * @param {number} id 
 * @param {string} stationName 
 * @param {number} t
 * @return {void}
 */
UndergroundSystem.prototype.checkOut = function(id, stationName, t) {
    const [checkInStationName, checkInTime] = this.checkInMap[id]
    const tripKey = `${checkInStationName}-${stationName}`
    
    if (!this.tripMap[tripKey]) this.tripMap[tripKey] = [0,0]
    
    this.tripMap[tripKey][0] += t - checkInTime
    this.tripMap[tripKey][1]++
};

/** 
 * @param {string} startStation 
 * @param {string} endStation
 * @return {number}
 */
UndergroundSystem.prototype.getAverageTime = function(startStation, endStation) {
    const tripkey = `${startStation}-${endStation}`
    const [totalTripTime, totalTrips] = this.tripMap[tripkey]
    return totalTripTime / totalTrips
};
