// Runtime: 101 ms (Top 25.0%) | Memory: 50.90 MB (Top 25.0%)

var containVirus = function(isInfected) {
    const directions = [[1, 0], [-1, 0], [0, 1], [0, -1]];
    let walls = 0;

    function findContaminated() {
        let visited = {}, infected = [];
        let mostViral;
        for (let i = 0; i < isInfected.length; i++) {
            for (let j = 0; j < isInfected[i].length; j++) {
                if (isInfected[i][j] === 1) {
                    let key = `${i}-${j}`;
                    if (key in visited) continue;
                    else infected.push([i, j]);
                    
                    let zeroes = new Set();
                    let perimeter = findPerimeter(i, j, visited, zeroes);

                    // Find the largest potential infection perimeter based on the number of 0's neighboring infected cells
                    if (!mostViral) mostViral = {i, j, perimeter, zeroes: zeroes.size};
                    else if (zeroes.size > mostViral.zeroes) mostViral = {i, j, perimeter, zeroes: zeroes.size};
                }
            }
        }
        if (mostViral) {
            walls += mostViral.perimeter;

            // Quarantine the most viral area
            quarantine(mostViral.i, mostViral.j);

            // Spread the infection throughout the remaining infected areas
            let alreadyInfected = {};
            for (let [row, col] of infected) {
                if (mostViral.i === row && mostViral.j === col) continue;
                else infect(row, col, alreadyInfected);
            }
            return true;
        }
        return false;
    }

    
    while (findContaminated()) continue;
    return walls;

    
    function findPerimeter(row, col, visited, zeroes) {
        if (row < 0 || col < 0 || row >= isInfected.length || col >= isInfected[0].length) return 0;
        let key = `${row}-${col}`;

        // If the current cell is visited or quarantined, leave the perimeter unchanged
        if (visited[key] || isInfected[row][col] === -1) return 0;
        
        // If the current cell is not infected and not quarantined, increase the perimeter
        if (isInfected[row][col] === 0) {
            zeroes.add(key);
            return 1;
        }
        
        visited[key] = true;
        let perimeter = 0;
        for (let [r, c] of directions) {
            perimeter += findPerimeter(row + r, col + c, visited, zeroes);
        }
        return perimeter;
    }

    function quarantine(row, col) {
        if (row < 0 || col < 0 || row >= isInfected.length || col >= isInfected[0].length) return;

        // Only quarantine infected cells and neighboring infected cells
        if (isInfected[row][col] === 1) isInfected[row][col] = -1;
        else return;

        for (let [r, c] of directions) quarantine(row + r, col + c);
    }
    
    function infect(row, col, alreadyInfected, neighbor = 0) {
        if (row < 0 || col < 0 || row >= isInfected.length || col >= isInfected[0].length) return;
        let key = `${row}-${col}`;
        
        // If the current cell is already infected or quarantined
        if (alreadyInfected[key] || isInfected[row][col] === -1) return;

        // If the current cell is clear but neighbors an infected cell, infect it
        if (isInfected[row][col] === 0 && neighbor === 1) {
            alreadyInfected[key] = true;
            return isInfected[row][col] = 1;
        }
        else if (isInfected[row][col] === 1 && neighbor === 1) {
            alreadyInfected[key] = true;
            neighbor = 0;
        }

        for (let [r, c] of directions) infect(row + r, col + c, alreadyInfected, neighbor + 1);
    }
};
