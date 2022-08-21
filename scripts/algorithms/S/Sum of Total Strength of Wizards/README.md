<h3 align="left"> 2281. Sum of Total Strength of Wizards</h3>
<div><p>As the ruler of a kingdom, you have an army of wizards at your command.</p>

<p>You are given a <strong>0-indexed</strong> integer array <code>strength</code>, where <code>strength[i]</code> denotes the strength of the <code>i<sup>th</sup></code> wizard. For a <strong>contiguous</strong> group of wizards (i.e. the wizards' strengths form a <strong>subarray</strong> of <code>strength</code>), the <strong>total strength</strong> is defined as the <strong>product</strong> of the following two values:</p>

<ul>
	<li>The strength of the <strong>weakest</strong> wizard in the group.</li>
	<li>The <strong>total</strong> of all the individual strengths of the wizards in the group.</li>
</ul>

<p>Return <em>the <strong>sum</strong> of the total strengths of <strong>all</strong> contiguous groups of wizards</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subarray</strong> is a contiguous <strong>non-empty</strong> sequence of elements within an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> strength = [1,3,1,2]
<strong>Output:</strong> 44
<strong>Explanation:</strong> The following are all the contiguous groups of wizards:
- [1] from [<u><strong>1</strong></u>,3,1,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [3] from [1,<u><strong>3</strong></u>,1,2] has a total strength of min([3]) * sum([3]) = 3 * 3 = 9
- [1] from [1,3,<u><strong>1</strong></u>,2] has a total strength of min([1]) * sum([1]) = 1 * 1 = 1
- [2] from [1,3,1,<u><strong>2</strong></u>] has a total strength of min([2]) * sum([2]) = 2 * 2 = 4
- [1,3] from [<u><strong>1,3</strong></u>,1,2] has a total strength of min([1,3]) * sum([1,3]) = 1 * 4 = 4
- [3,1] from [1,<u><strong>3,1</strong></u>,2] has a total strength of min([3,1]) * sum([3,1]) = 1 * 4 = 4
- [1,2] from [1,3,<u><strong>1,2</strong></u>] has a total strength of min([1,2]) * sum([1,2]) = 1 * 3 = 3
- [1,3,1] from [<u><strong>1,3,1</strong></u>,2] has a total strength of min([1,3,1]) * sum([1,3,1]) = 1 * 5 = 5
- [3,1,2] from [1,<u><strong>3,1,2</strong></u>] has a total strength of min([3,1,2]) * sum([3,1,2]) = 1 * 6 = 6
- [1,3,1,2] from [<u><strong>1,3,1,2</strong></u>] has a total strength of min([1,3,1,2]) * sum([1,3,1,2]) = 1 * 7 = 7
The sum of all the total strengths is 1 + 9 + 1 + 4 + 4 + 4 + 3 + 5 + 6 + 7 = 44.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> strength = [5,4,6]
<strong>Output:</strong> 213
<strong>Explanation:</strong> The following are all the contiguous groups of wizards: 
- [5] from [<u><strong>5</strong></u>,4,6] has a total strength of min([5]) * sum([5]) = 5 * 5 = 25
- [4] from [5,<u><strong>4</strong></u>,6] has a total strength of min([4]) * sum([4]) = 4 * 4 = 16
- [6] from [5,4,<u><strong>6</strong></u>] has a total strength of min([6]) * sum([6]) = 6 * 6 = 36
- [5,4] from [<u><strong>5,4</strong></u>,6] has a total strength of min([5,4]) * sum([5,4]) = 4 * 9 = 36
- [4,6] from [5,<u><strong>4,6</strong></u>] has a total strength of min([4,6]) * sum([4,6]) = 4 * 10 = 40
- [5,4,6] from [<u><strong>5,4,6</strong></u>] has a total strength of min([5,4,6]) * sum([5,4,6]) = 4 * 15 = 60
The sum of all the total strengths is 25 + 16 + 36 + 36 + 40 + 60 = 213.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= strength.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= strength[i] &lt;= 10<sup>9</sup></code></li>
</ul>
</div>