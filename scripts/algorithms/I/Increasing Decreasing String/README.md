<h3 align="left"> 1370. Increasing Decreasing String</h3>
<div><p>You are given a string <code>s</code>. Reorder the string using the following algorithm:</p>

<ol>
	<li>Pick the <strong>smallest</strong> character from <code>s</code> and <strong>append</strong> it to the result.</li>
	<li>Pick the <strong>smallest</strong> character from <code>s</code> which is greater than the last appended character to the result and <strong>append</strong> it.</li>
	<li>Repeat step 2 until you cannot pick more characters.</li>
	<li>Pick the <strong>largest</strong> character from <code>s</code> and <strong>append</strong> it to the result.</li>
	<li>Pick the <strong>largest</strong> character from <code>s</code> which is smaller than the last appended character to the result and <strong>append</strong> it.</li>
	<li>Repeat step 5 until you cannot pick more characters.</li>
	<li>Repeat the steps from 1 to 6 until you pick all characters from <code>s</code>.</li>
</ol>

<p>In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.</p>

<p>Return <em>the result string after sorting </em><code>s</code><em> with this algorithm</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> s = "aaaabbbbcccc"
<strong>Output:</strong> "abccbaabccba"
<strong>Explanation:</strong> After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> s = "rat"
<strong>Output:</strong> "art"
<strong>Explanation:</strong> The word "rat" becomes "art" after re-ordering it with the mentioned algorithm.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 500</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>
</div>