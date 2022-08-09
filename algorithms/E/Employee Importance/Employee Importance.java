class Solution {
    
    private Map<Integer, Integer> idToIndex;

    private void populateIdToIndexMap(List<Employee> employees) {         
        for(int idx = 0; idx<employees.size(); idx++) {
            idToIndex.put(employees.get(idx).id, idx);
        }
    }
    
    private int dfsGetImportance(List<Employee> employees, int id) {
        int currEmpIdx = idToIndex.get(id);
        Employee currEmp = employees.get(currEmpIdx);
        int totalImportance = currEmp.importance;
        for(int child : currEmp.subordinates) {
            totalImportance += dfsGetImportance(employees, child);
        }
        
        return totalImportance;
    }
    
    public int getImportance(List<Employee> employees, int id) {
        if(employees == null || employees.size() < 1) {
            return 0;            
        }
        
        idToIndex = new HashMap<>();
        populateIdToIndexMap(employees);
        return dfsGetImportance(employees, id);
    }
}
