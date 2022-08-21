<h3 align="left"> 1927. Sum Game</h3>
<div><p>Alice and Bob take turns playing a game, with <strong>Alice</strong><strong>&nbsp;starting first</strong>.</p>

<p>You are given a string <code>num</code> of <strong>even length</strong> consisting of digits and <code>'?'</code> characters. On each turn, a player will do the following if there is still at least one <code>'?'</code> in <code>num</code>:</p>

<ol>
	<li>Choose an index <code>i</code> where <code>num[i] == '?'</code>.</li>
	<li>Replace <code>num[i]</code> with any digit between <code>'0'</code> and <code>'9'</code>.</li>
</ol>

<p>The game ends when there are no more <code>'?'</code> characters in <code>num</code>.</p>

<p>For Bob&nbsp;to win, the sum of the digits in the first half of <code>num</code> must be <strong>equal</strong> to the sum of the digits in the second half. For Alice&nbsp;to win, the sums must <strong>not be equal</strong>.</p>

<ul>
	<li>For example, if the game ended with <code>num = "243801"</code>, then Bob&nbsp;wins because <code>2+4+3 = 8+0+1</code>. If the game ended with <code>num = "243803"</code>, then Alice&nbsp;wins because <code>2+4+3 != 8+0+3</code>.</li>
</ul>

<p>Assuming Alice and Bob play <strong>optimally</strong>, return <code>true</code> <em>if Alice will win and </em><code>false</code> <em>if Bob will win</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> num = "5023"
<strong>Output:</strong> false
<strong>Explanation:</strong> There are no moves to be made.
The sum of the first half is equal to the sum of the second half: 5 + 0 = 2 + 3.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> num = "25??"
<strong>Output:</strong> true
<strong>Explanation: </strong>Alice can replace one of the '?'s with '9' and it will be impossible for Bob to make the sums equal.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> num = "?3295???"
<strong>Output:</strong> false
<strong>Explanation:</strong> It can be proven that Bob will always win. One possible outcome is:
- Alice replaces the first '?' with '9'. num = "93295???".
- Bob replaces one of the '?' in the right half with '9'. num = "932959??".
- Alice replaces one of the '?' in the right half with '2'. num = "9329592?".
- Bob replaces the last '?' in the right half with '7'. num = "93295927".
Bob wins because 9 + 3 + 2 + 9 = 5 + 9 + 2 + 7.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num.length</code> is <strong>even</strong>.</li>
	<li><code>num</code> consists of only digits and <code>'?'</code>.</li>
</ul>
</div>