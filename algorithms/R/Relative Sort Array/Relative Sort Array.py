class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr = []
        hashmap = {char: arr1.count(char) for char in arr1}
        [arr.extend([char] * hashmap.pop(char)) for char in arr2]
        return arr + sorted([int(key) * hashmap[key] for key in hashmap]
