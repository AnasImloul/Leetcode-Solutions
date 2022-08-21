<h3 align="left"> 2266. Count Number of Texts</h3>
<div><p>Alice is texting Bob using her phone. The <strong>mapping</strong> of digits to letters is shown in the figure below.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2022/03/15/1200px-telephone-keypad2svg.png" style="width: 200px; height: 162px;">
<p>In order to <strong>add</strong> a letter, Alice has to <strong>press</strong> the key of the corresponding digit <code>i</code> times, where <code>i</code> is the position of the letter in the key.</p>

<ul>
	<li>For example, to add the letter <code>'s'</code>, Alice has to press <code>'7'</code> four times. Similarly, to add the letter <code>'k'</code>, Alice has to press <code>'5'</code> twice.</li>
	<li>Note that the digits <code>'0'</code> and <code>'1'</code> do not map to any letters, so Alice <strong>does not</strong> use them.</li>
</ul>

<p>However, due to an error in transmission, Bob did not receive Alice's text message but received a <strong>string of pressed keys</strong> instead.</p>

<ul>
	<li>For example, when Alice sent the message <code>"bob"</code>, Bob received the string <code>"2266622"</code>.</li>
</ul>

<p>Given a string <code>pressedKeys</code> representing the string received by Bob, return <em>the <strong>total number of possible text messages</strong> Alice could have sent</em>.</p>

<p>Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> pressedKeys = "22233"
<strong>Output:</strong> 8
<strong>Explanation:</strong>
The possible text messages Alice could have sent are:
"aaadd", "abdd", "badd", "cdd", "aaae", "abe", "bae", and "ce".
Since there are 8 possible messages, we return 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> pressedKeys = "222222222222222222222222222222222222"
<strong>Output:</strong> 82876089
<strong>Explanation:</strong>
There are 2082876103 possible text messages Alice could have sent.
Since we need to return the answer modulo 10<sup>9</sup> + 7, we return 2082876103 % (10<sup>9</sup> + 7) = 82876089.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= pressedKeys.length &lt;= 10<sup>5</sup></code></li>
	<li><code>pressedKeys</code> only consists of digits from <code>'2'</code> - <code>'9'</code>.</li>
</ul>
</div>