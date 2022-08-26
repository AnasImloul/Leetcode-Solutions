// Runtime: 144 ms (Top 53.60%) | Memory: 84.6 MB (Top 79.49%)
class OrderedStream {
    String[] values; //For index-wise data insertion
    int ptr = 0; //Starting position of pointer

    public OrderedStream(int n) {
        values = new String[n];
    }

    public List<String> insert(int idKey, String value) {
        List<String> output = new ArrayList();
        values[idKey - 1] = value;
        //While values[ptr] is filled, forward ptr
        while (ptr < values.length && values[ptr] != null) {
            output.add(values[ptr++]);
        }
        return output;
    }
}