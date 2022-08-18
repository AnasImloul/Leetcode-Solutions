// Runtime: 1401 ms (Top 5.55%) | Memory: 48.5 MB (Top 63.89%)

//""This solution isn`t the best way but it`s simple""
 var numTilePossibilities = function(tiles) {
    return search(tiles);
};
// this function takes a state and check if it`s valid or !
// valid state is not null state and unique
// e.g ["","A","A"]=>is not valid state because is has null state and repeated
// values by contrast ["A"] is valid state
// !!state below is to check if state not null
const isValidState=(state="",res=[])=>!!state&&!res.includes(state);
// this function permutes tiles by backtracking
const search=(tiles="",state='',result=[])=>{
    if(isValidState(state,result))//check if the current state valid
        result.push(state)
    //loop through tiles and every time you push letter to state
    // the remaining tiles will decreased by one
    /**
     * ---e.g--
     * level 1 tiles=AAB state=""
     * it will loop through the tiles ;
     * now I am in index 0 push tiles[0] to state now state=A
     * by making this operation number of option tiles will be
     * decreased to newTiles="AB"
     * ...
     * ..
     * .
     * */
    for(let i=0;i<tiles.length;i++){
        state+=tiles[i];
        const newTiles=tiles.substring(0,i)+tiles.substring(i+1);
        search(newTiles,state,result)
        state=state.slice(0,state.length-1);
    }
    return result.length;
}