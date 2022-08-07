class Solution {
    public String validIPAddress(String queryIP) {
        String regexIpv4 = "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])";
        
        String regexIpv6 = "((([0-9a-fA-F]){1,4})\\:){7}(([0-9a-fA-F]){1,4})";
        
        if(queryIP.matches(regexIpv4))
            return "IPv4";
        else if(queryIP.matches(regexIpv6))
            return "IPv6";
        else
            return "Neither";
    }
}