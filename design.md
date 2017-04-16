# Design

## Othello specific deisgn

### Node
1. alpha, beta
2. parent node
3. maximizer: our side
4. move
5. side: the side that maded the move leading to this node
6. Destructor delete board

### Move
1. x, y pair

### Board
1. enum Side { BLACK, WHITE};
2. Board
 - taken
 - black
3. isDone: no more legal moves for black and white
4. checkMoves: check if move legal for a given side
5. getMoves: generate all possible moves for a given side
6. onBoard: given position is in the board
7. doMoves: change board given a move
8. get and set board

### Decision Tree
1. Node root
2. Side maximiser
3. findBestMove given depth
4. search(Node startingNode, depth)
5. Order moves first before running anything according to evaluation
6. Killer heuristics: another move that works best may work here


### Evaluation 
1. count: number of discs for a particular side
2. getScore: returns score of a board given a side
3. Base score using piece differential

## [Transposition table](https://github.com/clarkkev/othello-ai/blob/master/src/othellosaurus/Node.java#L47)
1. Table entry
 - type: lower bound, exact, upper bound
 - value
 - depth: search depth
2. Table: HashMap: (board hashcode, table entry)

## [NegaMax with alpha-beta](https://github.com/electrojustin/c_checkers/blob/master/search.c#L74)

## MPI
1. [OpenMP vs MPI](http://stackoverflow.com/questions/11332018/mpi-vs-openmp-for-a-shared-memory)
2. [Parallel Checker with MPI](https://github.com/AboorvaDevarajan/Parallel-Checkers-Game)
 - one subtree assigned to one process
3. [Parallel Reversi Iroq](https://github.com/iroq/ParallelReversi/blob/master/reversi.c)
 - pv-split. Sequential on leftmost branch only parallelize

## Open MP
1. [Laserchess AlphaBeta Parallel](https://github.com/sphurti/Laserchess/blob/master/trees/AlphaBetaParallel.cpp)

## [MTD](https://github.com/peterbrook/Recursi-Othello-AI/tree/master/gamePlayer/algorithms)

## [Young Brothers Wait Concept](https://github.com/MichaelB7/Crafty/blob/master/src/search.c)

## Sequential game tree search
1. Alpha-beta, YBWC (works on random tree as well)
2. Negascout / PVS (assume strongly ordered tree)
 - requires very good evaluation function
 - effective at deeper depth
3. MTD(f)
 - heavily reliant on transposition table to prevent re-search
4. [Minimax](http://dhconnelly.com/paip-python/docs/paip/othello.html#minimax)
5. [NegaMax](file:///home/batumon/github/othellox/references/www.brucemo.com/compchess/programming/minmax.htm)
6. ER

## Parallel game tree search

1. [Shared Hash Table](https://chessprogramming.wikispaces.com/Shared+Hash+Table)
 - broadcast computed transposition entry to every other processes
 - lockless approach using Zobrist hashing
 - need to handle lock issues. Coarse granularity to avoid overhead due to locking
 - MPI-3 Remote Memory Access
2. Parallel Alpha-Beta
 - split at width
 - split at depth
3. Principle Variation Split / NegaScout
 - search leftmost branch or first node among siblings to remove dependency issues
 - the rest of the subtrees are ran in parallel
4. [Younger Brothers Wait Concept](https://pdfs.semanticscholar.org/12c8/0362791b9727165cf7d6d63c19033ed7ece2.pdf)
 - parallel evaluation of type-1 node v is allowed only if the first son has been evaluated
 - parallel evaluation of type-2 node v is allowed only if all promising sons have been evaluated
 - parallel evaluation of type-3 node can be evaluated anytime
 - promising sons are moves recommended by killer heuristic or transposition table
 - distributed transposition table
5. [Dynamic Tree Splitting (DTS)](https://chessprogramming.wikispaces.com/Dynamic+Tree+Splitting)
 - solves problem of all processors working on a single node.
 - if one processor selects very bushy tree, the rest needed to wait
 - just like PVS but when processors got nothing to work, broadcast to other processors it is available to help
6. [ABDADA](http://chessprogramming.wikispaces.com/ABDADA?showComments=1)
 - easy to implement
 - good for small and deep problems
 - when message passing is slow, this works very well for shared memory
 - requires fast global transposition table
7. [Parallelized Randomized Best-first minimax search](https://pdfs.semanticscholar.org/b011/4b5be80355b72cc864c0b654b8693b353ddc.pdf)
 - perform random walk from a node to its children based on distribution associated with the node
 - uses negamax where score = maximum of negated scores of its children
