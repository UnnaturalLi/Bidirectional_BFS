# Bidirectional BFS  Puzzle Solver
# (A lot to optimize, but I hope it makes sense to you ^_^)

## About the Toy
This project is based on a puzzle toy from haidilao.
The puzzle has 10 grids arranged like this:
```
1 1 1
1 1 1
1 1 1
0 0 1
```

- 1 means a reachable grid.
- 0 means an empty space (slot).

There are 9 movable blocks placed on the 1s.
You can scramble them, and the goal is to bring them back into the correct order.
## Algorithm
This project uses Bidirectional BFS to solve the puzzle efficiently.
(Still lots of room for optimization!)
