<h3 align="left"> 884. Uncommon Words from Two Sentences</h3>
<div><p>A <strong>sentence</strong> is a string of single-space separated words where each word consists only of lowercase letters.</p>

<p>A word is <strong>uncommon</strong> if it appears exactly once in one of the sentences, and <strong>does not appear</strong> in the other sentence.</p>

<p>Given two <strong>sentences</strong> <code>s1</code> and <code>s2</code>, return <em>a list of all the <strong>uncommon words</strong></em>. You may return the answer in <strong>any order</strong>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<pre><strong>Input:</strong> s1 = "this apple is sweet", s2 = "this apple is sour"
<strong>Output:</strong> ["sweet","sour"]
</pre><p><strong>Example 2:</strong></p>
<pre><strong>Input:</strong> s1 = "apple apple", s2 = "banana"
<strong>Output:</strong> ["banana"]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s1.length, s2.length &lt;= 200</code></li>
	<li><code>s1</code> and <code>s2</code> consist of lowercase English letters and spaces.</li>
	<li><code>s1</code> and <code>s2</code> do not have leading or trailing spaces.</li>
	<li>All the words in <code>s1</code> and <code>s2</code> are separated by a single space.</li>
</ul>
</div>