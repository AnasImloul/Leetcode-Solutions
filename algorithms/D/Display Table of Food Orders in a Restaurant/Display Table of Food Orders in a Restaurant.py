class Solution:
    def displayTable(self, orders: List[List[str]]) -> List[List[str]]:
        column = ['Table']
        dish = []
        table_dict = {}
        for order_row in orders : 
            if order_row[-1] not in dish :
                dish.append(order_row[-1])
        
        for order_row in orders :
            if order_row[1] not in table_dict.keys() :
                table_dict[order_row[1]] = {}
                for food in dish : 
                    table_dict[order_row[1]][food] = 0 
                table_dict[order_row[1]][order_row[-1]] += 1
            else : 
               table_dict[order_row[1]][order_row[-1]] += 1 
        
        dish.sort()
        column = column + dish 
        ans = [column]
        table = []
        childDict = {}
        for key in sorted(table_dict.keys()) : 
            table.append(int(key))
            childDict[key] = []
            for value in column : 
                if value != 'Table' :
                    childDict[key].append(str(table_dict[key][value]))
        table.sort()
        output = [ans[0]]
        for table_num in table : 
            childList = [str(table_num)]
            output.append(childList + childDict[str(table_num)])
        return output 
