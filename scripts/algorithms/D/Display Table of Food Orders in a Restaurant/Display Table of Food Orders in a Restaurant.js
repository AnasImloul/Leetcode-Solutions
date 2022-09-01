// Runtime: 355 ms (Top 14.58%) | Memory: 72.6 MB (Top 6.25%)
var displayTable = function(orders) {
    var mapOrders = {};
    var tables = [];
    var dishes = [];
    for(var i=0;i<orders.length;i++){
        //if entry of table doesn't exist in mapOrders
        if(mapOrders[orders[i][1]] == undefined){
            //conver table number to integer
            var tableNo = Number(orders[i][1])
            mapOrders[tableNo] = {}
            mapOrders[tableNo][orders[i][2]] = 1;
            //if table number doesn't exist in table array, push it in the table array
            if(!tables.includes(tableNo)){tables.push(tableNo)}
            //if dish doesn't exist in dishes array, push it in the dishes array
            if(!dishes.includes(orders[i][2])){dishes.push(orders[i][2])}
        }else{
            //if entry of table exists in mapOrders
            //conver table number to integer
            var tableNo = Number(orders[i][1])
            var entry = mapOrders[tableNo];
            //check if entry of dish exists in for that table in mapOrders
            if(entry[orders[i][2]] == undefined){
                entry[orders[i][2]] = 1;
            }else{
                entry[orders[i][2]] = entry[orders[i][2]] + 1;
            }
            //if dish doesn't exist in dishes array, push it in the dishes array
            if(!dishes.includes(orders[i][2])){dishes.push(orders[i][2])}
        }
    }
    //sort tables and dishes
    tables.sort(function(a,b){return a-b});
    dishes.sort();
    //append word "Table" with all dish names om row[0] of result
    var res = [["Table"]];
    for(var i=0;i<dishes.length;i++){
        res[0].push(dishes[i]);
    }
    // read through map based on sorted table order
    for(var i=0;i<tables.length;i++){
        // append result in a temp array
        var tmp = [];
        //converting number to string using ""+
        tmp.push(""+tables[i]);
        for(var j=0;j<dishes.length;j++){
            if(mapOrders[tables[i]][dishes[j]]==undefined){
                //if dish doesn't exist against that table then append "0" to the result for that dish
                tmp.push(""+0);
            }else{
                //if dish exists against that table then append value in mapOrders for that pair of (table,dish) to the result
                tmp.push(""+mapOrders[tables[i]][dishes[j]]);
            }
        }
        //append the temp array in result
        res.push(tmp);
    }
    return res;
};