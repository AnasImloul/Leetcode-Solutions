var validUtf8 = function(data) {
  const len = data.length;
  const byteBits = data.map(a => padLeft(a.toString(2))); //convert to bit strings
  let bytes,  i = 0;
  while (i < len) {
    bytes = 0;
    //count 1s in the front.
    while (byteBits[i].charAt(bytes) === "1") bytes++;

    //if we have only 1 byte to process expect more than 1 byte, it should fail.
    if (len === 1 && bytes > 0) return false;

    //UTF8 chars can't be more than 4 bytes.
    if (bytes > 4) return false;

    //if we're processing more than 1 byte
    if (bytes > 1) {
      //decrement for every byte that starts with "10"
      while (i < len - 1 && byteBits[++i].startsWith("10")) bytes--;

      //check to see if we have too many or too little of the expected bytes left
      if (bytes !== 1) return false;
    }
    else i++;
  }
  return true;
};

const padLeft = (str, size = 8, pad = "0") => (
  str.length >= size ? str : pad.repeat(size).substring(str.length % size) + str
);
