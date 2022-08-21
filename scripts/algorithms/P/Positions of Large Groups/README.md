<h3 align="left"> 830. Positions of Large Groups</h3>
<div><p>In a string <code><font face="monospace">s</font></code>&nbsp;of lowercase letters, these letters form consecutive groups of the same character.</p>

<p>For example, a string like <code>s = "abbxxxxzyy"</code> has the groups <code>"a"</code>, <code>"bb"</code>, <code>"xxxx"</code>, <code>"z"</code>, and&nbsp;<code>"yy"</code>.</p>

<p>A group is identified by an interval&nbsp;<code>[start, end]</code>, where&nbsp;<code>start</code>&nbsp;and&nbsp;<code>end</code>&nbsp;denote the start and end&nbsp;indices (inclusive) of the group. In the above example,&nbsp;<code>"xxxx"</code>&nbsp;has the interval&nbsp;<code>[3,6]</code>.</p>

<p>A group is considered&nbsp;<strong>large</strong>&nbsp;if it has 3 or more characters.</p>

<p>Return&nbsp;<em>the intervals of every <strong>large</strong> group sorted in&nbsp;<strong>increasing order by start index</strong></em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "abbxxxxzzy"
<strong>Output:</strong> [[3,6]]
<strong>Explanation:</strong> <code>"xxxx" is the only </code>large group with start index 3 and end index 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "abc"
<strong>Output:</strong> []
<strong>Explanation:</strong> We have groups "a", "b", and "c", none of which are large groups.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> s = "abcdddeeeeaabbbcd"
<strong>Output:</strong> [[3,5],[6,9],[12,14]]
<strong>Explanation:</strong> The large groups are "ddd", "eeee", and "bbb".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 1000</code></li>
	<li><code>s</code> contains lowercase English letters only.</li>
</ul>
</div>