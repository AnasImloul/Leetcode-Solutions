// Runtime: 566 ms (Top 49.45%) | Memory: 88.2 MB (Top 18.68%)
var rotateTheBox = function(box) {
  for(let r=0; r<box.length;r++){
    let idx = null
    for(let c = 0;c<box[r].length;c++){
      const curr = box[r][c]
      if(curr === '*'){
        idx = null
        continue
      }
      if(curr === '#' && idx === null){
        idx = c
        continue
      }
      if(curr === '.' &&
         box[r][idx] === '#' &&
         idx <= c){
        box[r][idx] = '.'
        box[r][c] = '#'
        idx++
      }
    }
  }
  return transpose(box)
};

function transpose(arr){
  const B = []
  for(let c = 0; c < arr[0].length; c++){
    if(!B[c]) B[c] = []
    for(let r = 0; r < arr.length; r++){
      B[c][r] = arr[r][c]
    }
    B[c].reverse()
  }
  return B
}