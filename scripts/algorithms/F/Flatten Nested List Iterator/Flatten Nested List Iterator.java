// Runtime: 4 ms (Top 77.47%) | Memory: 46.1 MB (Top 81.31%)
public class NestedIterator implements Iterator<Integer> {
    List<Integer> list=new ArrayList();
    void flatten(List<NestedInteger> nestedList){
        for(NestedInteger nested:nestedList){
            if(nested.isInteger())
                list.add(nested.getInteger());
            else
                flatten(nested.getList());
        }
    }
    public NestedIterator(List<NestedInteger> nestedList) {
        flatten(nestedList);
    }
    int index=0;
    @Override
    public Integer next() {
        return list.get(index++);
    }

    @Override
    public boolean hasNext() {
        return index<list.size();
    }
}