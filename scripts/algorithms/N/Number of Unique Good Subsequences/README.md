<h3 align="left"> 1987. Number of Unique Good Subsequences</h3>
<div><p>You are given a binary string <code>binary</code>. A <strong>subsequence</strong> of <code>binary</code> is considered <strong>good</strong> if it is <strong>not empty</strong> and has <strong>no leading zeros</strong> (with the exception of <code>"0"</code>).</p>

<p>Find the number of <strong>unique good subsequences</strong> of <code>binary</code>.</p>

<ul>
	<li>For example, if <code>binary = "001"</code>, then all the <strong>good</strong> subsequences are <code>["0", "0", "1"]</code>, so the <strong>unique</strong> good subsequences are <code>"0"</code> and <code>"1"</code>. Note that subsequences <code>"00"</code>, <code>"01"</code>, and <code>"001"</code> are not good because they have leading zeros.</li>
</ul>

<p>Return <em>the number of <strong>unique good subsequences</strong> of </em><code>binary</code>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>A <strong>subsequence</strong> is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> binary = "001"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The good subsequences of binary are ["0", "0", "1"].
The unique good subsequences are "0" and "1".
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> binary = "11"
<strong>Output:</strong> 2
<strong>Explanation:</strong> The good subsequences of binary are ["1", "1", "11"].
The unique good subsequences are "1" and "11".</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> binary = "101"
<strong>Output:</strong> 5
<strong>Explanation:</strong> The good subsequences of binary are ["1", "0", "1", "10", "11", "101"]. 
The unique good subsequences are "0", "1", "10", "11", and "101".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= binary.length &lt;= 10<sup>5</sup></code></li>
	<li><code>binary</code> consists of only <code>'0'</code>s and <code>'1'</code>s.</li>
</ul>
</div>