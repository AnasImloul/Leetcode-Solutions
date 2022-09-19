// Runtime: 111 ms (Top 16.67%) | Memory: 42.1 MB (Top 37.04%)
var validIPAddress = function(queryIP) {
    const iPv4 = () => {
        const address = queryIP.split('.');
        if (address.length !== 4) return null;

        for (const str of address) {
            const ip = parseInt(str);
            if (ip < 0 || ip > 255) return null;
            if (ip.toString() !== str) return null;
        }
        return 'IPv4';
    };

    const iPv6 = () => {
        const address = queryIP.split(':');
        if (address.length !== 8) return null;
        const config = '0123456789abcdefABCDEF';
        const check = address.every(str => {
            if (str === '' || str.length > 4) return false;
            for (const s of str) {
                if (!config.includes(s)) return false;
            }
            return true;
        });
        return check ? 'IPv6' : null;
    };

    return iPv4() ?? iPv6() ?? 'Neither';
};