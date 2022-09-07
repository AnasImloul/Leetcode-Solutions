# Runtime: 31 ms (Top 93.30%) | Memory: 13.8 MB (Top 98.50%)
class Solution:
    def reformatDate(self, date: str) -> str:

        m_dict_={"Jan":"01", "Feb":"02", "Mar":"03", "Apr":"04", "May":"05", "Jun":"06", "Jul":"07", "Aug":"08", "Sep":"09", "Oct":"10", "Nov":"11", "Dec":"12"}

        day=date[:-11]

        if len(day)==1:
            day="0"+day

        return(date[-4:] + "-" + m_dict_[date[-8:-5]] + "-" + day)