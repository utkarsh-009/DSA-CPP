/*
You are given N identical eggs and a building with K floors. You need to find the floor f, where 0 <= f <= K, such that dropping an egg from any floor above f will cause it to break, and dropping it from or below f will not break it.
The following rules apply:
- An egg that survives a fall can be reused.
- A broken egg cannot be used again.
- The effect of a fall is the same for all eggs.
- If an egg doesn't break at a certain floor, it will not break at any floor below.
- If an egg breaks at a certain floor, it will break at any floor above.

You need to determine the minimum number of moves required to find the value of f with certainty.
*/