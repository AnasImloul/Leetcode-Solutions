<h3 align="left"> 1798. Maximum Number of Consecutive Values You Can Make</h3>
<div><p>You are given an integer array <code>coins</code> of length <code>n</code> which represents the <code>n</code> coins that you own. The value of the <code>i<sup>th</sup></code> coin is <code>coins[i]</code>. You can <strong>make</strong> some value <code>x</code> if you can choose some of your <code>n</code> coins such that their values sum up to <code>x</code>.</p>

<p>Return the <em>maximum number of consecutive integer values that you <strong>can</strong> <strong>make</strong> with your coins <strong>starting</strong> from and <strong>including</strong> </em><code>0</code>.</p>

<p>Note that you may have multiple coins of the same value.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> coins = [1,3]
<strong>Output:</strong> 2
<strong>Explanation: </strong>You can make the following values:
- 0: take []
- 1: take [1]
You can make 2 consecutive integer values starting from 0.</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> coins = [1,1,1,4]
<strong>Output:</strong> 8
<strong>Explanation: </strong>You can make the following values:
- 0: take []
- 1: take [1]
- 2: take [1,1]
- 3: take [1,1,1]
- 4: take [4]
- 5: take [4,1]
- 6: take [4,1,1]
- 7: take [4,1,1,1]
You can make 8 consecutive integer values starting from 0.</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> nums = [1,4,10,3,1]
<strong>Output:</strong> 20</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>coins.length == n</code></li>
	<li><code>1 &lt;= n &lt;= 4 * 10<sup>4</sup></code></li>
	<li><code>1 &lt;= coins[i] &lt;= 4 * 10<sup>4</sup></code></li>
</ul>
</div>