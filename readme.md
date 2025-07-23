# DSA Practice Repository

This repo is my personal grind zone for Data Structures and Algorithms, following **Striver’s 455-question playlist/DSA sheet**. It’s a structured collection of solutions organized by topic and difficulty to level up my problem-solving game.

## Repo Structure

- `03.Array/03` — Array problems.
- `04.BinarySearch` — Binary Search techniques.
- `06.LinkedList` — Linked List challenges.
- `07.Recursion` — Recursion-based problems.
- `08.BitManipulation` — Bit manipulation tricks.
- `09.StacksQueues` — Stacks and Queues.
- `10.SlidingWindow` — Sliding window pattern.
- `11.Heaps` — Heap data structures.
- `12.Greedy` — Greedy algorithms.
- `14.BST` — Binary Search Tree problems.
- `15.Graph` — Graph algorithms.
- `16.DP` — Dynamic Programming.

## Automation Script - `git.sh`

A quick Linux shell script to automate Git pushes:

- Adds all changes (`git add .`)
- Commits with current timestamp as message (`git commit -m "$DATE"`)
- Pushes to `main` branch (`git push origin main`)

Make it executable with:

```bash
chmod +x git.sh
