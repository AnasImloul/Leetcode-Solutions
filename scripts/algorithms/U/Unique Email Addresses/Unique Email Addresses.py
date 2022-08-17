class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        def ets(email):
            s, domain = email[:email.index('@')], email[email.index('@'):]
            s = s.replace(".", "")
            s = s[:s.index('+')] if '+' in s else s
            return s+domain
        dict = {}
        for i in emails:
            dict[ets(i)] = 1
        return len(dict)
