var findLeastNumOfUniqueInts = function(arr, k) {
    var hsh = {};
    var instance = {};  // store set with index # of occurence
    var count = 0;
    for (var i = 0; i < arr.length; i++)
    {
        if (hsh[arr[i]] == null)
        {
            count ++;
            hsh[arr[i]] = 1;
            if (instance[1] == null)
            {
                var intro = new Set();
                intro.add(arr[i]);
                instance[1] = intro;
            }
            else
            {
                instance[1].add(arr[i]);
            }
        }
        else
        {
            hsh[arr[i]] ++;
            var numTimes = hsh[arr[i]];
            instance[numTimes - 1].delete(arr[i]);
            
            if (instance[numTimes] == null)
            {
                instance[numTimes] = new Set();
                instance[numTimes].add(arr[i]);
            }
            else
            {
                instance[numTimes].add(arr[i]);
            }
        }
    }
    
    var removenum = 0;
    
    for (key in instance)
    {
        var instanceKey = instance[key].size;
        if (k == 0)
        {
            break;
        }
        else if (k >= key*instanceKey)
        {
            k -= key*instanceKey;
            count -= instanceKey;
        }
        else
        {
            count -= Math.floor(k/key);
            break;
        }
        
    }
    return count;
};
