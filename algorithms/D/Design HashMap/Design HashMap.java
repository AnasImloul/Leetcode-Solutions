class MyHashMap {

	/** Initialize your data structure here. */
	LinkedList<Entry>[] map;
	public static int SIZE = 769;
	public MyHashMap() {
		map = new LinkedList[SIZE];
	}

	/** value will always be non-negative. */
	public void put(int key, int value) {
		int bucket = key % SIZE;
		if(map[bucket] == null) {
			map[bucket] = new LinkedList<Entry>();
			map[bucket].add(new Entry(key, value));
		}
		else {
			for(Entry entry : map[bucket]){
				if(entry.key == key){
					entry.val = value;
					return;
				}
			}
			map[bucket].add(new Entry(key, value));
		}
	}

	/** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
	public int get(int key) {
		int bucket = key % SIZE;
		LinkedList<Entry> entries = map[bucket];
		if(entries == null) return -1;
		for(Entry entry : entries) {
			if(entry.key == key) return entry.val;
		}
		return -1;
	}

	/** Removes the mapping of the specified value key if this map contains a mapping for the key */
	public void remove(int key) {
		int bucket = key % SIZE;
		Entry toRemove = null;
		if(map[bucket] == null) return;
		else {
			for(Entry entry : map[bucket]){
				if(entry.key == key) {
					toRemove = entry;
				}
			}
			if(toRemove == null) return;
			map[bucket].remove(toRemove);
		}
	}
}

class Entry {
	public int key;
	public int val;

	public Entry(int key, int val){
		this.key = key;
		this.val = val;
	}
}