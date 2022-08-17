var isCovered = function(ranges, left, right) {
  var map=new Map()
  for(let i=left;i<=right;i++){
      map.set(i,0)
  }
  for(let range of ranges){
      for(let i=range[0];i<=range[1];i++){
          map.set(i,1)
      }
  }
    // console.log(map)
  for(let key of map.keys()){
      if(map.get(key)===0) return false
  }
    return true
};
