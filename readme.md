# DSA using C++ Notes

All Striver's A-Z's sheet question solution along with approch.

## 15. Graph

Around 56 question are there which includes:

| Type             | Number                                                                |
| ----------------- | ------------------------------------------------------------------ |
| Reprentation | 2 |
| Traversal (BFS / DFS) | 2 |




#### 1. Matrix Representation

##### i. Adjacency List

```cpp
vector<vector<int>> g = {
        {},
        {2, 6},
        {1, 3, 4},
        {2},
        {2, 5},
        {4, 8},
        {1, 7, 9},
        {6, 8},
        {5, 7},
        {9}};
```

##### ii. Matrix Format

```cpp
vector<vector<int>> g = {
        {0, 0, 0, 1, 1},
        {0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 1, 1}
    };
```