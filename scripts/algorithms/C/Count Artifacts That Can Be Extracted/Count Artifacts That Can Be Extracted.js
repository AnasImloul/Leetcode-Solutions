// Runtime: 215 ms (Top 66.67%) | Memory: 127.70 MB (Top 16.67%)

/**
 * @param {number} n
 * @param {number[][]} artifacts
 * @param {number[][]} dig
 * @return {number}
 */
var digArtifacts = function(n, artifacts, dig) {
   // Step 1
    const virtualMap = [] // 0 = null, n = artifact_n
    for (let x = 0; x< n; x++){
        const row = []
        for(let y = 0; y<n; y++){
            row.push(0)
        }
        virtualMap.push(row)
    }
	
	// Step 2
    const artifactSize = []
    for(let artifactIdx in artifacts){
        let [artY1, artX1, artY2, artX2] = artifacts[artifactIdx]
        artifactSize.push((artX2 + 1 - artX1) * (artY2 + 1 - artY1))
        while(artY1 <= artY2){
            while(artX1 <= artX2){
                virtualMap[artY1][artX1] = Number(artifactIdx)+1
                artX1++
            }
            artY1++
            artX1 = artifacts[artifactIdx][1]
        }
    }

    // Step 3
    for(let digComp of dig){
        const [digY, digX] = digComp
        const content = virtualMap[digY][digX]
        if(content !== 0){
            artifactSize[content-1] -= 1 
        }
    }

    // Step 4
    return artifactSize.reduce((acc, remainder) => {
        if(remainder === 0){
            acc++
        }
        return acc
    }, 0)
};
