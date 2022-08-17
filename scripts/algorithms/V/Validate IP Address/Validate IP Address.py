class Solution:
    def validIPAddress(self, queryIP: str) -> str:
        ipv4 = re.compile(r"((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])\.){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])")
        ipv6 = re.compile(r"([0-9A-Fa-f]{1,4}:){7}([0-9A-Fa-f]{1,4})")
        if ipv4.fullmatch(queryIP) :
            return "IPv4"
        if ipv6.fullmatch(queryIP) :
            return "IPv6"
        return "Neither"
		
