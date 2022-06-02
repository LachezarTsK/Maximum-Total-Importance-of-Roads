
/**
 * @param {number} numberOfCities
 * @param {number[][]} roads
 * @return {number}
 */
var maximumImportance = function (numberOfCities, roads) {
    const connections = new Array(numberOfCities).fill(0);
    for (let road of roads) {
        ++connections[road[0]];
        ++connections[road[1]];
    }
    connections.sort((cityOne, cityTwo) => cityOne - cityTwo);
    return connections.map((cityConnections, cityValue) => cityConnections * (cityValue + 1))
                      .reduce((cityOne, cityTwo) => cityOne + cityTwo);
};
