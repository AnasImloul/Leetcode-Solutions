<h3 align="left"> 2102. Sequentially Ordinal Rank Tracker</h3>
<div><p>A scenic location is represented by its <code>name</code> and attractiveness <code>score</code>, where <code>name</code> is a <strong>unique</strong> string among all locations and <code>score</code> is an integer. Locations can be ranked from the best to the worst. The <strong>higher</strong> the score, the better the location. If the scores of two locations are equal, then the location with the <strong>lexicographically smaller</strong> name is better.</p>

<p>You are building a system that tracks the ranking of locations with the system initially starting with no locations. It supports:</p>

<ul>
	<li><strong>Adding</strong> scenic locations, <strong>one at a time</strong>.</li>
	<li><strong>Querying</strong> the <code>i<sup>th</sup></code> <strong>best</strong> location of <strong>all locations already added</strong>, where <code>i</code> is the number of times the system has been queried (including the current query).
	<ul>
		<li>For example, when the system is queried for the <code>4<sup>th</sup></code> time, it returns the <code>4<sup>th</sup></code> best location of all locations already added.</li>
	</ul>
	</li>
</ul>

<p>Note that the test data are generated so that <strong>at any time</strong>, the number of queries <strong>does not exceed</strong> the number of locations added to the system.</p>

<p>Implement the <code>SORTracker</code> class:</p>

<ul>
	<li><code>SORTracker()</code> Initializes the tracker system.</li>
	<li><code>void add(string name, int score)</code> Adds a scenic location with <code>name</code> and <code>score</code> to the system.</li>
	<li><code>string get()</code> Queries and returns the <code>i<sup>th</sup></code> best location, where <code>i</code> is the number of times this method has been invoked (including this invocation).</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input</strong>
["SORTracker", "add", "add", "get", "add", "get", "add", "get", "add", "get", "add", "get", "get"]
[[], ["bradford", 2], ["branford", 3], [], ["alps", 2], [], ["orland", 2], [], ["orlando", 3], [], ["alpine", 2], [], []]
<strong>Output</strong>
[null, null, null, "branford", null, "alps", null, "bradford", null, "bradford", null, "bradford", "orland"]

<strong>Explanation</strong>
SORTracker tracker = new SORTracker(); // Initialize the tracker system.
tracker.add("bradford", 2); // Add location with name="bradford" and score=2 to the system.
tracker.add("branford", 3); // Add location with name="branford" and score=3 to the system.
tracker.get();              // The sorted locations, from best to worst, are: branford, bradford.
                            // Note that branford precedes bradford due to its <strong>higher score</strong> (3 &gt; 2).
                            // This is the 1<sup>st</sup> time get() is called, so return the best location: "branford".
tracker.add("alps", 2);     // Add location with name="alps" and score=2 to the system.
tracker.get();              // Sorted locations: branford, alps, bradford.
                            // Note that alps precedes bradford even though they have the same score (2).
                            // This is because "alps" is <strong>lexicographically smaller</strong> than "bradford".
                            // Return the 2<sup>nd</sup> best location "alps", as it is the 2<sup>nd</sup> time get() is called.
tracker.add("orland", 2);   // Add location with name="orland" and score=2 to the system.
tracker.get();              // Sorted locations: branford, alps, bradford, orland.
                            // Return "bradford", as it is the 3<sup>rd</sup> time get() is called.
tracker.add("orlando", 3);  // Add location with name="orlando" and score=3 to the system.
tracker.get();              // Sorted locations: branford, orlando, alps, bradford, orland.
                            // Return "bradford".
tracker.add("alpine", 2);   // Add location with name="alpine" and score=2 to the system.
tracker.get();              // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                            // Return "bradford".
tracker.get();              // Sorted locations: branford, orlando, alpine, alps, bradford, orland.
                            // Return "orland".
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>name</code> consists of lowercase English letters, and is unique among all locations.</li>
	<li><code>1 &lt;= name.length &lt;= 10</code></li>
	<li><code>1 &lt;= score &lt;= 10<sup>5</sup></code></li>
	<li>At any time, the number of calls to <code>get</code> does not exceed the number of calls to <code>add</code>.</li>
	<li>At most <code>4 * 10<sup>4</sup></code> calls <strong>in total</strong> will be made to <code>add</code> and <code>get</code>.</li>
</ul>
</div>