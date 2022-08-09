var longestDecomposition = function(text) {
    var i = 1
    var output = 0
    while(i < text.length)
    {
        if(text.substring(0,i) == text.substring(text.length-i))
        {
            output += 2 //add 2 to simulate adding to both sides of output array
            text = text.substring(i,text.length-i) //cut text to simulate popping off of both sides
            i=1
        } else {
            i++
        }
    }
    
    return text ? output + 1 : output //if there's any text leftover that didn't have a match, it's the middle and would add 1 to output array
}
