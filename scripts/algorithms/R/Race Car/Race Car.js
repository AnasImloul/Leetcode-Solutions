// Runtime: 56 ms (Top 92.31%) | Memory: 46.30 MB (Top 65.38%)

/**
 * @param {number} target
 * @return {number}
 */
var racecar = function(target) {    
    const queue = [{position: 0, speed: 1, sequence: ""}]

    while(queue.length){
        let { position, speed, sequence } = queue.shift()
        
        if(position === target) return sequence.length

        const newPosition = position + speed

        queue.push({ position: newPosition, speed: speed*2, sequence: sequence + 'A' })
        
        if(newPosition > target && speed > 0 || newPosition < target && speed < 0) {
            queue.push({ sequence: sequence + 'R', position, speed: Math.sign(speed) === 1 ? -1:1 })
        }
    }

    return 0
};

