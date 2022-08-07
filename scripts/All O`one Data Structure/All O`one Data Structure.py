from collections import defaultdict


class Set(object):

    def __init__(self):
        self._dict = {}
        self._list = []
        self._len = 0

    def add(self, v):
        if v in self._dict:
            pass
        else:
            self._list.append(v)
            self._dict[v] = self._len
            self._len += 1

    def __contains__(self, item):
        return item in self._dict

    def remove(self, v):
        if v not in self._dict:
            pass
        else:
            idx = self._dict[v]

            if idx < self._len - 1:
                self._list[idx] = self._list[-1]
                self._dict[self._list[idx]] = idx

            del self._dict[v]
            self._list.pop()
            self._len -= 1

    def __iter__(self):
        return iter(self._list)

    def check(self):
        assert len(self._dict) == len(self._list)
        for idx, key in enumerate(self._list):
            assert self._dict[key] == idx

    def __len__(self):
        return self._len

    def __repr__(self):
        return f"{self._dict}\n{self._list}"


class Node(object):

    def __init__(self, value):
        self.value = value
        self.prev = None
        self.next = None

    def set_prev(self, other_node):
        self.prev = other_node
        if other_node is not None:
            other_node.next = self

    def set_next(self, other_node):
        self.next = other_node
        if other_node is not None:
            other_node.prev = self

    def __repr__(self):
        return str(self.value)


class SortedKeyList(object):

    def __init__(self):
        self.head = Node(value=0)
        self.tail = Node(value=float("inf"))
        self.head.set_next(self.tail)

    def is_empty(self):
        return self.head.next is self.tail

    def min_key(self):
        if self.is_empty():
            return None
        else:
            return self.head.next.value

    def max_key(self):
        if self.is_empty():
            return None
        else:
            return self.tail.prev.value

    def incr_key(self, orig_node):
        orig_value = orig_node.value
        new_value = orig_value + 1
        next_node = orig_node.next
        if next_node.value == new_value:
            return self
        else:
            new_node = Node(new_value)
            new_node.set_prev(orig_node)
            new_node.set_next(next_node)
            return self

    def decr_key(self, orig_node):
        orig_value = orig_node.value
        new_value = orig_value - 1
        prev_node = orig_node.prev
        if prev_node.value == new_value:
            return self
        else:
            new_node = Node(new_value)
            new_node.set_next(orig_node)
            new_node.set_prev(prev_node)
            return self

    def delete_node(self, node):
        prev_node = node.prev
        next_node = node.next
        prev_node.set_next(next_node)
        return self

    def __repr__(self):
        a = []
        node = self.head.next
        while True:
            if node is self.tail:
                break

            assert node.next.prev is node
            assert node.prev.next is node

            a.append(node.value)
            node = node.next
        return str(a)


class AllOne:

    def __init__(self):
        self.count_list = SortedKeyList()
        self.counter = defaultdict(lambda: self.count_list.head)
        self.keyed_by_count = defaultdict(set)

    def __repr__(self):
        return f"count_list={self.count_list}\ncounter={dict(self.counter)}\nkeyed_by_count={dict(self.keyed_by_count)}"

    def inc(self, key: str) -> None:
        orig_count_node = self.counter[key]
        orig_count = orig_count_node.value

        self.count_list.incr_key(orig_count_node)
        new_count_node = orig_count_node.next
        new_count = new_count_node.value
        assert new_count == orig_count + 1

        self.counter[key] = new_count_node

        if key in self.keyed_by_count[orig_count]:
            self.keyed_by_count[orig_count].remove(key)
        self.keyed_by_count[new_count].add(key)

        if len(self.keyed_by_count[orig_count]) == 0:
            del self.keyed_by_count[orig_count]
            if orig_count_node.value > 0:
                self.count_list.delete_node(orig_count_node)

    def dec(self, key: str) -> None:
        orig_count_node = self.counter[key]
        orig_count = orig_count_node.value

        self.count_list.decr_key(orig_count_node)
        new_count_node = orig_count_node.prev
        new_count = new_count_node.value
        assert new_count == orig_count - 1

        self.counter[key] = new_count_node

        if key in self.keyed_by_count[orig_count]:
            self.keyed_by_count[orig_count].remove(key)
        self.keyed_by_count[new_count].add(key)

        if new_count == 0:
            del self.counter[key]

        if len(self.keyed_by_count[orig_count]) == 0:
            del self.keyed_by_count[orig_count]
            self.count_list.delete_node(orig_count_node)

    def getMaxKey(self) -> str:
        max_count = self.count_list.max_key()
        if max_count is not None:
            return next(iter(self.keyed_by_count[max_count]))
        else:
            return ""

    def getMinKey(self) -> str:
        min_count = self.count_list.min_key()
        if min_count is not None:
            return next(iter(self.keyed_by_count[min_count]))
        else:
            return ""


def drive(m, p):
    s = AllOne()

    naive_counter = defaultdict(int)

    for method, param in zip(m, p):
        if method in ("inc", "dec"):
            word = param[0]

            if method == "inc":
                s.inc(word)
                naive_counter[word] += 1

            elif method == 'dec':
                s.dec(word)
                naive_counter[word] -= 1

            if naive_counter[word] == 0:
                del naive_counter[word]

            tmp_counter = defaultdict(set)
            for k, v in naive_counter.items():
                tmp_counter[v].add(k)

            sorted_keys = sorted(tmp_counter.keys())
            min_key = sorted_keys[0]
            max_key = sorted_keys[-1]

            if s.getMaxKey() not in tmp_counter[max_key]:
                print("Oh No!!!")
                return s, naive_counter, tmp_counter

            if s.getMinKey() not in tmp_counter[min_key]:
                print("Oh No!!!")
                return s, naive_counter, tmp_counter

    return None, None, None


if __name__ == '__main__':
    m = ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
    p = [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
    s, naive_counter, tmp_counter = drive(m, p)
