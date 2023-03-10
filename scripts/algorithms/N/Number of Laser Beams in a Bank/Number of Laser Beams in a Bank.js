var numberOfBeams = function(bank) {
    let totalBeams = 0;
    const maximumSecurityDevicePerRow = bank.map(row => (row.match(/1/g) || []).length).filter(Boolean)
    for (let index = 0; index < maximumSecurityDevicePerRow.length - 1; index++) 
        totalBeams+= maximumSecurityDevicePerRow[index] * maximumSecurityDevicePerRow[index + 1];
    return totalBeams;
};