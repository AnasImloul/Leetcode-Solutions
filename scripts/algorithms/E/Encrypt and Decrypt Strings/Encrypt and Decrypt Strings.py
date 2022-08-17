class Encrypter:

    def __init__(self, keys: List[str], values: List[str], dictionary: List[str]):
        self.hashmap = dict()
        for i in range(len(keys)):
            self.hashmap[keys[i]] = values[i]
        self.dictmap = defaultdict(int)
        for word in dictionary:
            self.dictmap[self.encrypt(word)] += 1

    def encrypt(self, word1: str) -> str:
        output = ''
        for char in word1:
            output += self.hashmap[char]
        return output

    def decrypt(self, word2: str) -> int:
        return self.dictmap[word2]
