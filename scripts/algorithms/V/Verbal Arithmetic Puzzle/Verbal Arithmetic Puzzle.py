class Solution:
    def isSolvable(self, words: List[str], result: str) -> bool:
        
        # reverse words
        words = [i[::-1] for i in words]
        result = result[::-1]
        allWords = words + [result]
        
        # chars that can not be 0
        nonZero = set()
        for word in allWords:
            if len(word) > 1:
                nonZero.add(word[-1])
        
        # numbers selected in backtracking
        selected = set()
        # char to Int map
        charToInt = dict()
        mxLen = max([len(i) for i in allWords])
        
        def res(i = 0, c = 0, sm = 0):
            if c == mxLen:
                return 1 if sm == 0 else 0
            elif i == len(words):
                num = sm % 10
                carry = sm // 10
                if c >= len(result):
                    if num == 0:
                        return res(0, c+1, carry)
                    else:
                        return 0
                # result[c] should be mapped to num if a mapping exists
                if result[c] in charToInt:
                    if charToInt[result[c]] != num:
                        return 0
                    else:
                        return res(0, c+1, carry)
                elif num in selected:
                    return 0
                # if mapping does not exist, create a mapping
                elif (num == 0 and result[c] not in nonZero) or num > 0:
                    selected.add(num)
                    charToInt[result[c]] = num
                    ret = res(0, c + 1, carry)
                    del charToInt[result[c]]
                    selected.remove(num)
                    return ret
                else:
                    return 0
            else:
                word = words[i]
                if c >= len(word):
                    return res(i+1, c, sm)
                elif word[c] in charToInt:
                    return res(i+1, c, sm + charToInt[word[c]])
                else:
                    ret = 0
                    # possibilities for word[c]
                    for j in range(10):
                        if (j == 0 and word[c] not in nonZero) or j > 0:
                            if j not in selected:
                                selected.add(j)
                                charToInt[word[c]] = j
                                ret += res(i + 1, c, sm + j)
                                del charToInt[word[c]]
                                selected.remove(j)
                    return ret
        
        return res() > 0