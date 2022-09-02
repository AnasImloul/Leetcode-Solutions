// Runtime: 7877 ms (Top 5.15%) | Memory: 105.2 MB (Top 88.00%)

var NumberContainers = function() {
    this.obj = {}
    this.global = {}
};

NumberContainers.prototype.change = function(index, number) {

    if(this.global[index])
        {
            for(var key in this.obj)
            {
               let ind = this.obj[key].indexOf(index)
                if(ind != -1)
                    {
                         this.obj[key].splice(ind, 1);
                        if(this.obj[number])
                            this.obj[number].push(index);
                        else
                            this.obj[number] = [index];

                        this.global[index]=1;
                        return;
                    }
            }
        }

    if(this.obj[number])
        this.obj[number].push(index);
    else
        this.obj[number] = [index];
    this.global[index]=1;
};

NumberContainers.prototype.find = function(number) {
    if(this.obj[number])
        {
            if(this.obj[number].length == 0)
                return -1
            else
                return Math.min(...this.obj[number])
        }
    return -1;
};