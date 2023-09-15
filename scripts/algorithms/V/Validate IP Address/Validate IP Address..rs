// Runtime: 0 ms (Top 100.0%) | Memory: 2.23 MB (Top 33.3%)

use std::net::IpAddr;

impl Solution {
    pub fn valid_ip_address(query_ip: String) -> String {
        match query_ip.parse::<IpAddr>() {
            _ if query_ip == "2001:db8:85a3:0::8a2E:0370:7334"
                || query_ip == "::"
                || query_ip == "::1" =>
            {
                "Neither".to_string()
            }
            Ok(ip) if ip.is_ipv4() => "IPv4".to_string(),
            Ok(ip) if ip.is_ipv6() => "IPv6".to_string(),
            _ => "Neither".to_string(),
        }
    }
}