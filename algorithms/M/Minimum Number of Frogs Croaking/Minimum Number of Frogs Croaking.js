var minNumberOfFrogs = function(croakOfFrogs) {
    const croakArr = new Array(5).fill(0); //Array to store occurence of each char
    let overlap = 0;  //Store the number of overlaps
    for(let i = 0; i < croakOfFrogs.length; i++) {
        switch(croakOfFrogs[i]) {
            case 'c':
                croakArr[0] += 1;
                //Check if new start, is overlapping with others
                if((croakArr[0] - croakArr[4] - overlap) > 1) {
                    ++overlap;
                }
                break;
            case 'r':
                //Condition to check if r comes before c
                if(croakArr[0] <= croakArr[1]) return -1;
                croakArr[1] += 1;
                break;
            case 'o':
                //Condition to check if o comes before r
                if(croakArr[1] <= croakArr[2]) return -1;
                croakArr[2] += 1;
                break;
            case 'a':
                //Condition to check if a comes before o
                if(croakArr[2] <= croakArr[3]) return -1;
                croakArr[3] += 1;
                break;
            case 'k':
                //Condition to check if k comes before a
                if(croakArr[3] <= croakArr[4]) return -1;
                croakArr[4] += 1;
                break;
        }
    }
    //Check if all items of array have same count else return -1
    //If all items have same count return overlap + 1
    return (Math.max(...croakArr) === Math.min(...croakArr)) ? overlap + 1 : -1;
};
