// Runtime: 443 ms (Top 37.00%) | Memory: 86.7 MB (Top 40.00%)
var maximumImportance = function(n, roads) {
    const connectionCount = Array(n).fill(0)

    // Count the connections from each city
    // e.g. the 0th city's count will be stored at index zero in the array
    for (let [cityTo, cityFrom] of roads) {
        connectionCount[cityTo]++
        connectionCount[cityFrom]++
    }

    let cityToConnectionCount = []
    for (let city = 0; city < n; city++) {
        cityToConnectionCount.push([city, connectionCount[city]])// Store the [city, numberOfConnections]
    }

    // Created new array(sortedCities) for readability
    const sortedCities = cityToConnectionCount.sort((a,b) => b[1] - a[1])// sort by number of connections, the city with the greatest number of connections should be
    // the city with the greatest importance

    const values = Array(n).fill(0)
    let importance = n
    for (let i = 0; i < sortedCities.length; i++) {
        const [city, connectionCount] = cityToConnectionCount[i]
        values[city] = importance// City at the 0th position array is should be the city with the greatest importance
        importance--
    }

    // Sum the importance of each city, toCity => fromCity
    let res = 0
    for (let [to, from] of roads) {
        res += values[to] + values[from]
    }

    return res
};```