<h3 align="left"> 1872. Stone Game VIII</h3>
<div><p>Alice and Bob take turns playing a game, with <strong>Alice starting first</strong>.</p>

<p>There are <code>n</code> stones arranged in a row. On each player's turn, while the number of stones is <strong>more than one</strong>, they will do the following:</p>

<ol>
	<li>Choose an integer <code>x &gt; 1</code>, and <strong>remove</strong> the leftmost <code>x</code> stones from the row.</li>
	<li>Add the <strong>sum</strong> of the <strong>removed</strong> stones' values to the player's score.</li>
	<li>Place a <strong>new stone</strong>, whose value is equal to that sum, on the left side of the row.</li>
</ol>

<p>The game stops when <strong>only</strong> <strong>one</strong> stone is left in the row.</p>

<p>The <strong>score difference</strong> between Alice and Bob is <code>(Alice's score - Bob's score)</code>. Alice's goal is to <strong>maximize</strong> the score difference, and Bob's goal is the <strong>minimize</strong> the score difference.</p>

<p>Given an integer array <code>stones</code> of length <code>n</code> where <code>stones[i]</code> represents the value of the <code>i<sup>th</sup></code> stone <strong>from the left</strong>, return <em>the <strong>score difference</strong> between Alice and Bob if they both play <strong>optimally</strong>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> stones = [-1,2,-3,4,-5]
<strong>Output:</strong> 5
<strong>Explanation:</strong>
- Alice removes the first 4 stones, adds (-1) + 2 + (-3) + 4 = 2 to her score, and places a stone of
  value 2 on the left. stones = [2,-5].
- Bob removes the first 2 stones, adds 2 + (-5) = -3 to his score, and places a stone of value -3 on
  the left. stones = [-3].
The difference between their scores is 2 - (-3) = 5.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> stones = [7,-6,5,10,5,-2,-6]
<strong>Output:</strong> 13
<strong>Explanation:</strong>
- Alice removes all stones, adds 7 + (-6) + 5 + 10 + 5 + (-2) + (-6) = 13 to her score, and places a
  stone of value 13 on the left. stones = [13].
The difference between their scores is 13 - 0 = 13.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> stones = [-10,-12]
<strong>Output:</strong> -22
<strong>Explanation:</strong>
- Alice can only make one move, which is to remove both stones. She adds (-10) + (-12) = -22 to her
  score and places a stone of value -22 on the left. stones = [-22].
The difference between their scores is (-22) - 0 = -22.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == stones.length</code></li>
	<li><code>2 &lt;= n &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= stones[i] &lt;= 10<sup>4</sup></code></li>
</ul></div>