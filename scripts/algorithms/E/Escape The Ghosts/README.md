<h3 align="left"> 789. Escape The Ghosts</h3>
<div><p>You are playing a simplified PAC-MAN game on an infinite 2-D grid. You start at the point <code>[0, 0]</code>, and you are given a destination point <code>target = [x<sub>target</sub>, y<sub>target</sub>]</code> that you are trying to get to. There are several ghosts on the map with their starting positions given as a 2D array <code>ghosts</code>, where <code>ghosts[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents the starting position of the <code>i<sup>th</sup></code> ghost. All inputs are <strong>integral coordinates</strong>.</p>

<p>Each turn, you and all the ghosts may independently choose to either <strong>move 1 unit</strong> in any of the four cardinal directions: north, east, south, or west, or <strong>stay still</strong>. All actions happen <strong>simultaneously</strong>.</p>

<p>You escape if and only if you can reach the target <strong>before</strong> any ghost reaches you. If you reach any square (including the target) at the <strong>same time</strong> as a ghost, it <strong>does not</strong> count as an escape.</p>

<p>Return <code>true</code><em> if it is possible to escape regardless of how the ghosts move, otherwise return </em><code>false</code><em>.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> ghosts = [[1,0],[0,3]], target = [0,1]
<strong>Output:</strong> true
<strong>Explanation:</strong> You can reach the destination (0, 1) after 1 turn, while the ghosts located at (1, 0) and (0, 3) cannot catch up with you.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> ghosts = [[1,0]], target = [2,0]
<strong>Output:</strong> false
<strong>Explanation:</strong> You need to reach the destination (2, 0), but the ghost at (1, 0) lies between you and the destination.
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> ghosts = [[2,0]], target = [1,0]
<strong>Output:</strong> false
<strong>Explanation:</strong> The ghost can reach the target at the same time as you.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= ghosts.length &lt;= 100</code></li>
	<li><code>ghosts[i].length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>i</sub>, y<sub>i</sub> &lt;= 10<sup>4</sup></code></li>
	<li>There can be <strong>multiple ghosts</strong> in the same location.</li>
	<li><code>target.length == 2</code></li>
	<li><code>-10<sup>4</sup> &lt;= x<sub>target</sub>, y<sub>target</sub> &lt;= 10<sup>4</sup></code></li>
</ul>
</div>