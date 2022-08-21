<h3 align="left"> 911. Online Election</h3>
<div><p>You are given two integer arrays <code>persons</code> and <code>times</code>. In an election, the <code>i<sup>th</sup></code> vote was cast for <code>persons[i]</code> at time <code>times[i]</code>.</p>

<p>For each query at a time <code>t</code>, find the person that was leading the election at time <code>t</code>. Votes cast at time <code>t</code> will count towards our query. In the case of a tie, the most recent vote (among tied candidates) wins.</p>

<p>Implement the <code>TopVotedCandidate</code> class:</p>

<ul>
	<li><code>TopVotedCandidate(int[] persons, int[] times)</code> Initializes the object with the <code>persons</code> and <code>times</code> arrays.</li>
	<li><code>int q(int t)</code> Returns the number of the person that was leading the election at time <code>t</code> according to the mentioned rules.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["TopVotedCandidate", "q", "q", "q", "q", "q", "q"]
[[[0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]], [3], [12], [25], [15], [24], [8]]
<strong>Output</strong>
[null, 0, 1, 1, 0, 0, 1]

<strong>Explanation</strong>
TopVotedCandidate topVotedCandidate = new TopVotedCandidate([0, 1, 1, 0, 0, 1, 0], [0, 5, 10, 15, 20, 25, 30]);
topVotedCandidate.q(3); // return 0, At time 3, the votes are [0], and 0 is leading.
topVotedCandidate.q(12); // return 1, At time 12, the votes are [0,1,1], and 1 is leading.
topVotedCandidate.q(25); // return 1, At time 25, the votes are [0,1,1,0,0,1], and 1 is leading (as ties go to the most recent vote.)
topVotedCandidate.q(15); // return 0
topVotedCandidate.q(24); // return 0
topVotedCandidate.q(8); // return 1

</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= persons.length &lt;= 5000</code></li>
	<li><code>times.length == persons.length</code></li>
	<li><code>0 &lt;= persons[i] &lt; persons.length</code></li>
	<li><code>0 &lt;= times[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>times</code> is sorted in a strictly increasing order.</li>
	<li><code>times[0] &lt;= t &lt;= 10<sup>9</sup></code></li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>q</code>.</li>
</ul>
</div>