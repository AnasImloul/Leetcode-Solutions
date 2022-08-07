class MyQueue {

	private final Deque<Integer> stack = new ArrayDeque<>();
	private final Deque<Integer> temp = new ArrayDeque<>();

	/**
	 * Initialize your data structure here.
	 */
	public MyQueue() {}

	/**
	 * Pushes element x to the back of the queue.
	 */
	public void push(int x) {
		stack.push(x);
	}

	/**
	 * @return the element at the front of the queue and remove it.
	 */
	public int pop() {
		while (stack.size() > 1)
			temp.push(stack.pop());

		var val = stack.pop();
		while (!temp.isEmpty())
			stack.push(temp.pop());

		return val;
	}

	/**
	 * @return the element at the front of the queue.
	 */
	public int peek() {
		while (stack.size() > 1)
			temp.push(stack.pop());

		var val = stack.peek();
		while (!temp.isEmpty())
			stack.push(temp.pop());

		return val;
	}

	/**
	 * @return true if the queue is empty, false otherwise.
	 */
	public boolean empty() {
		return stack.isEmpty();
	}
}
