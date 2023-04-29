class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        queryIP = queryIP.replace(".",":")
        ct = 0
        for i in queryIP.split(":"):
            if i != "":
                ct += 1
        if ct == 4:
            for i in queryIP.split(":"):
                if i == "":
                    return "Neither"
                if i.isnumeric():
                    if len(i) > 1:
                        if i.count('0') == len(i) or int(i) > 255 or i[0] == '0':
                            return "Neither"
                else:
                    return "Neither"
            return "IPv4"
        elif ct == 8:
            a = ['a','b','c','d','e','f','A','B','C','D','E','F']
            for i in queryIP.split(":"):
                if i == "":
                    return "Neither"
                if len(i) < 5:
                    for j in i:
                        if j not in a and j.isdigit() == False:
                            return "Neither"
                else:
                    return "Neither"
            return "IPv6"
        else:
            return "Neither"
                   


        