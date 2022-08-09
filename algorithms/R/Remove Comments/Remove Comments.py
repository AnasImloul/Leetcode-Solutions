class Solution:
    def removeComments(self, source: List[str]) -> List[str]:
        output = []
        source_index, string_index = 0, 0
        
        
        def is_open(source_i, string_i):
            try:
                symbol = source[source_i][string_i] + source[source_i][string_i + 1]
                if symbol == '/*':
                    return find_close(source_i, string_i + 2)
                elif symbol == '//':
                    return (source_i + 1, 0, True)
                else:
                    return None
            except IndexError:
                return None
        
        
        def is_close(source_i, string_i):
            try:
                symbol = source[source_i][string_i] + source[source_i][string_i + 1]
                if symbol == '*/':
                    return (source_i, string_i + 2, False) if len(source[source_i]) != string_i + 2 else (source_i + 1, 0, False)
                else:
                    return None
            except IndexError:
                return None
        
        
        def find_close(source_i, string_i):
            if string_i == len(source[source_i]):
                return find_close(source_i + 1, 0)
            
            is_closed = is_close(source_i, string_i)
            while is_closed is None:
                string_i += 1
                if len(source[source_i]) <= string_i:
                    source_i += 1
                    string_i = 0
                is_closed = is_close(source_i, string_i)
                
            return is_closed
        
        
        curr_string = ''
        while source_index != len(source):
            if string_index == len(source[source_index]):
                if curr_string != '':
                    output.append(curr_string)
                string_index = 0
                source_index += 1
                curr_string = ''
                continue
            
            where_it_is_closes = is_open(source_index, string_index)
            if where_it_is_closes is None:
                curr_string += source[source_index][string_index]
                string_index += 1
                continue
            
            new_source_index, new_string_index, double_slash = where_it_is_closes
            if new_source_index == source_index:
                source_index = new_source_index
                string_index = new_string_index
                continue
            
            if curr_string != '' and (double_slash or new_string_index == 0):
                output.append(curr_string)
                curr_string = ''
            
            source_index = new_source_index
            string_index = new_string_index
        
        return output
