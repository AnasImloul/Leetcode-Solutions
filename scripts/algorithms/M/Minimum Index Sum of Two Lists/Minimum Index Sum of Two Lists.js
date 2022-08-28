// Runtime: 170 ms (Top 33.33%) | Memory: 48.8 MB (Top 57.06%)
var findRestaurant = function(list1, list2) {
    let obj ={}
    for(let i =0; i <list1.length; i ++){
        if(list2.indexOf(list1[i]) !==-1){
            const sum = i+ list2.indexOf(list1[i])
            if(obj[sum]!==undefined)
                {
                    obj[sum]['value'].push(list1[i])
                }
            else{
                obj[sum]={}
                obj[sum]['sum']=sum
                obj[sum]['value']=[]
                obj[sum]['value'].push(list1[i])
            }

        }
    }
    return Object.values(obj)[0]['value']

};