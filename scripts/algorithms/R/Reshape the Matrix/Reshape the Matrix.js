
var matrixReshape = function(mat, r, c) {
  const origR = mat.length;
  const origC = mat[0].length;
  
  if (r*c !== origR*origC) {
    return mat;
  }
  
  const flat = mat.flatMap(n => n);
  
  const output = [];
  for (let i=0; i<flat.length; i++) {
    if (i%c === 0) {
      output.push([]);
    }
    
    output[output.length-1].push(flat[i]);
  };
  return output;
};

