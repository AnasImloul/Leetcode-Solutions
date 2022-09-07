# Runtime: 1004 ms (Top 5.08%) | Memory: 28.1 MB (Top 35.29%)
class Solution:
    def getFolderNames(self, names: List[str]) -> List[str]:
        # Hashmap will store the name as key and the number of times that name has duplicated so fas as value.
        hashmap = {}

        for name in names:
            modified = name
            # Check whether the name has already been used
            if name in hashmap:
                # Get the number of times the {name} has been used
                k = hashmap[name]
                # Calculate the next available suffix.
                while modified in hashmap:
                    k += 1
                    modified = f'{name}({k})'
                # Update the number of times the original {name} is used. This will help to efficiently check for next available suffix if the {name} again comes in future.
                hashmap[name] = k
            # Store the modified {name} with 0 as it is not duplicated yet.
            hashmap[modified] = 0

        # Return the keys of hashmap as that would be the unique file names.
        return hashmap.keys()