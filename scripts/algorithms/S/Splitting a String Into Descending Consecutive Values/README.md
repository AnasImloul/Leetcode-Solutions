<h3 align="left"> 1849. Splitting a String Into Descending Consecutive Values</h3>
<div><p>You are given a string <code>s</code> that consists of only digits.</p>

<p>Check if we can split <code>s</code> into <strong>two or more non-empty substrings</strong> such that the <strong>numerical values</strong> of the substrings are in <strong>descending order</strong> and the <strong>difference</strong> between numerical values of every two <strong>adjacent</strong> <strong>substrings</strong> is equal to <code>1</code>.</p>

<ul>
	<li>For example, the string <code>s = "0090089"</code> can be split into <code>["0090", "089"]</code> with numerical values <code>[90,89]</code>. The values are in descending order and adjacent values differ by <code>1</code>, so this way is valid.</li>
	<li>Another example, the string <code>s = "001"</code> can be split into <code>["0", "01"]</code>, <code>["00", "1"]</code>, or <code>["0", "0", "1"]</code>. However all the ways are invalid because they have numerical values <code>[0,1]</code>, <code>[0,1]</code>, and <code>[0,0,1]</code> respectively, all of which are not in descending order.</li>
</ul>

<p>Return <code>true</code> <em>if it is possible to split</em> <code>s</code>​​​​​​ <em>as described above</em><em>, or </em><code>false</code><em> otherwise.</em></p>

<p>A <strong>substring</strong> is a contiguous sequence of characters in a string.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "1234"
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid way to split s.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "050043"
<strong>Output:</strong> true
<strong>Explanation:</strong> s can be split into ["05", "004", "3"] with numerical values [5,4,3].
The values are in descending order with adjacent values differing by 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "9080701"
<strong>Output:</strong> false
<strong>Explanation:</strong> There is no valid way to split s.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 20</code></li>
	<li><code>s</code> only consists of digits.</li>
</ul>
</div>