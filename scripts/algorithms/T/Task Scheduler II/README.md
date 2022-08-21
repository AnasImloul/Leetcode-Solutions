<h3 align="left"> 2365. Task Scheduler II</h3>
<div><p>You are given a <strong>0-indexed</strong> array of positive integers <code>tasks</code>, representing tasks that need to be completed <strong>in order</strong>, where <code>tasks[i]</code> represents the <strong>type</strong> of the <code>i<sup>th</sup></code> task.</p>

<p>You are also given a positive integer <code>space</code>, which represents the <strong>minimum</strong> number of days that must pass <strong>after</strong> the completion of a task before another task of the <strong>same</strong> type can be performed.</p>

<p>Each day, until all tasks have been completed, you must either:</p>

<ul>
	<li>Complete the next task from <code>tasks</code>, or</li>
	<li>Take a break.</li>
</ul>

<p>Return<em> the <strong>minimum</strong> number of days needed to complete all tasks</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> tasks = [1,2,1,2,3,1], space = 3
<strong>Output:</strong> 9
<strong>Explanation:</strong>
One way to complete all tasks in 9 days is as follows:
Day 1: Complete the 0th task.
Day 2: Complete the 1st task.
Day 3: Take a break.
Day 4: Take a break.
Day 5: Complete the 2nd task.
Day 6: Complete the 3rd task.
Day 7: Take a break.
Day 8: Complete the 4th task.
Day 9: Complete the 5th task.
It can be shown that the tasks cannot be completed in less than 9 days.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> tasks = [5,8,8,5], space = 2
<strong>Output:</strong> 6
<strong>Explanation:</strong>
One way to complete all tasks in 6 days is as follows:
Day 1: Complete the 0th task.
Day 2: Complete the 1st task.
Day 3: Take a break.
Day 4: Take a break.
Day 5: Complete the 2nd task.
Day 6: Complete the 3rd task.
It can be shown that the tasks cannot be completed in less than 6 days.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= tasks.length &lt;= 10<sup>5</sup></code></li>
	<li><code>1 &lt;= tasks[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= space &lt;= tasks.length</code></li>
</ul>
</div>