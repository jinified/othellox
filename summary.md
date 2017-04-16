# Summary

## Sequential Algorithms (increasing order more efficient)

1. Minimax / NegaMax
2. Alpha-beta
3. PVS
4. NegaScout
5. MTD(f)

## Board representation
1. Bitboard
2. Array
3. Adjacent table
4. Direction table

## Parallel method
1. PV Split, Dynamic multiple PV Split
2. YWBC and Helpful Master
3. Dynamic Tree Splitting
4. Delayed Branched Tree Expansion
5. Parallelized Best-first minimax

## Enhancement method
1. Move ordering
 - transposition table
 - killer heuristic
 - history heuristic
2. Minimal window search / aspiration window
 - zero-window
 - nega scout
3. Null move pruning
4. Forward pruning
 - multi-prob cut

## Evaluation function
1. Piece differential = number of my pieces - number of opponent pieces
2. Mobility differential = number of my legal moves - number of opponent legal moves
3. 4-corners differential = number of 4-corners on our side - opponent's
4. 8-corners differential = number of 8-corners on our side - opponent's
5. Frontier differential = number of our pieces adjacent to empty squares in any direction -
   oppponent's
6. Stable piece differential = number of piece that cannot be flipped by enemy
7. Mobility
 - number of moves available to player - opponent's
 - empty squares adjacent to player's pieces. Less frontier squares better
8. Stability
 - Corners are extremely stable
 - X-squares: square diagonally adjacent to corner. Negative weight
 - C-squares: squares adjacent to corner and along edge. Slightlt less negative thatn X-square

## Parallelization model
1. SMP (Symmetric multiprocessing) involves a multiprocessor system with centralized shared memory
2. Explore pure MPI or OpenMP + MPI

## Design choices
1. [Why 1D array over 2D array](http://stackoverflow.com/questions/17259877/1d-or-2d-array-whats-faster)
