class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        # Keep track of how many continuation bytes are left
		# Start at 0 since we are not expecting any continuation bytes at the beginning.
        cont_bytes_left = 0
        for byte in data:
            if cont_bytes_left == 0:
			    # If we don't expect any continuation bytes
			    # then there are 4 valid case for the current byte
                # byte >> 5 gives us the first 3 bits (8 bits - 5 = 3).
                if byte >> 5 == 0b110:
				    # After seeing a byte that starts with 110,
					# we expect to see one continuation byte
                    cont_bytes_left = 1
                elif byte >> 4 == 0b1110:
                    cont_bytes_left = 2
                elif byte >> 3 == 0b11110:
                    cont_bytes_left = 3
                # finally if the first bit isn't 0 then it's invalid
                elif byte >> 7 != 0:
                    return False
            else:
			    # If we are expecting a continuation byte there is only one valid case.
                # It's invalid if the continuation byte doesn't start with 10
                if byte >> 6 != 0b10:
                    return False
                cont_bytes_left -= 1
        
		# Only valid if we aren't expecting any more continuation bytes
        return cont_bytes_left == 0
