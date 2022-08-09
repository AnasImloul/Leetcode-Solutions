class Solution(object):
    def reorderLogFiles(self, logs):
        """
        :type logs: List[str]
        :rtype: List[str]
        """
        self._seq=0
        def _sortBy(log):
            a=log.split(' ')
            logType,self._seq=('A',self._seq) if a[1].isalpha() else ('B',self._seq+1)
            return (logType," ".join(a[1:]),a[0]) if logType=='A' else (logType,self._seq)
        return sorted(logs,key=_sortBy)
