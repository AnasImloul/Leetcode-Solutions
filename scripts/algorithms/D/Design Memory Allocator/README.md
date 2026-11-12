<h3 align="left"> 2502. Design Memory Allocator</h3>
<div><p>You are given an integer <code>n</code> representing the size of a <strong>0-indexed</strong> memory array. All memory units are initially free.</p>

<p>You have a memory allocator with the following functionalities:</p>

<ol>
	<li><strong>Allocate </strong>a block of <code>size</code> consecutive free memory units and assign it the id <code>mID</code>.</li>
	<li><strong>Free</strong> all memory units with the given id <code>mID</code>.</li>
</ol>

<p><strong>Note</strong> that:</p>

<ul>
	<li>Multiple blocks can be allocated to the same <code>mID</code>.</li>
	<li>You should free all the memory units with <code>mID</code>, even if they were allocated in different blocks.</li>
</ul>

<p>Implement the <code>Allocator</code> class:</p>

<ul>
	<li><code>Allocator(int n)</code> Initializes an <code>Allocator</code> object with a memory array of size <code>n</code>.</li>
	<li><code>int allocate(int size, int mID)</code> Find the <strong>leftmost</strong> block of <code>size</code> <strong>consecutive</strong> free memory units and allocate it with the id <code>mID</code>. Return the block&#39;s first index. If such a block does not exist, return <code>-1</code>.</li>
	<li><code>int freeMemory(int mID)</code> Free all memory units with the id <code>mID</code>. Return the number of memory units you have freed.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;Allocator&quot;, &quot;allocate&quot;, &quot;allocate&quot;, &quot;allocate&quot;, &quot;freeMemory&quot;, &quot;allocate&quot;, &quot;allocate&quot;, &quot;allocate&quot;, &quot;freeMemory&quot;, &quot;allocate&quot;, &quot;freeMemory&quot;]
[[10], [1, 1], [1, 2], [1, 3], [2], [3, 4], [1, 1], [1, 1], [1], [10, 2], [7]]
<strong>Output</strong>
[null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]

<strong>Explanation</strong>
Allocator loc = new Allocator(10); // Initialize a memory array of size 10. All memory units are initially free.
loc.allocate(1, 1); // The leftmost block&#39;s first index is 0. The memory array becomes [<strong>1</strong>,_,_,_,_,_,_,_,_,_]. We return 0.
loc.allocate(1, 2); // The leftmost block&#39;s first index is 1. The memory array becomes [1,<strong>2</strong>,_,_,_,_,_,_,_,_]. We return 1.
loc.allocate(1, 3); // The leftmost block&#39;s first index is 2. The memory array becomes [1,2,<strong>3</strong>,_,_,_,_,_,_,_]. We return 2.
loc.freeMemory(2); // Free all memory units with mID 2. The memory array becomes [1,_, 3,_,_,_,_,_,_,_]. We return 1 since there is only 1 unit with mID 2.
loc.allocate(3, 4); // The leftmost block&#39;s first index is 3. The memory array becomes [1,_,3,<strong>4</strong>,<strong>4</strong>,<strong>4</strong>,_,_,_,_]. We return 3.
loc.allocate(1, 1); // The leftmost block&#39;s first index is 1. The memory array becomes [1,<strong>1</strong>,3,4,4,4,_,_,_,_]. We return 1.
loc.allocate(1, 1); // The leftmost block&#39;s first index is 6. The memory array becomes [1,1,3,4,4,4,<strong>1</strong>,_,_,_]. We return 6.
loc.freeMemory(1); // Free all memory units with mID 1. The memory array becomes [_,_,3,4,4,4,_,_,_,_]. We return 3 since there are 3 units with mID 1.
loc.allocate(10, 2); // We can not find any free block with 10 consecutive free memory units, so we return -1.
loc.freeMemory(7); // Free all memory units with mID 7. The memory array remains the same since there is no memory unit with mID 7. We return 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n, size, mID &lt;= 1000</code></li>
	<li>At most <code>1000</code> calls will be made to <code>allocate</code> and <code>freeMemory</code>.</li>
</ul>
</div>
