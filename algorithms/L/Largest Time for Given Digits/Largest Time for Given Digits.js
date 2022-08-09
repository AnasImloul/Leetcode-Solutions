var largestTimeFromDigits = function(arr) {
    let max=-1;
    for(let A=0; A<4; A++){
        for(let B=0; B<4; B++){
			if(B==A){continue};
            for(let C=0; C<4; C++){
				if(C==A||C==B||arr[C]>=6){continue};
                for(let D=0; D<4; D++){
					if(D==A||D==B||D==C){continue};
                    let time=arr[A]*1000+arr[B]*100+arr[C]*10+arr[D];
                    if(time<2400){max=Math.max(max, time));
                }
            }
        }
    }
	// Case1: max<0, which means NOTHING VALID -> return ""
	// Case2: max isn't 4 digits. i.e.[0,0,0,0] -> padStart to make "0000"
    let output=max.toString().padStart(4,0);
    return max<0? "": output.substr(0,2)+":"+output.substr(2);
};
