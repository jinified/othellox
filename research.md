# Research

## A Comparative Study of Game Tree Searching Methods

### Sequential Game Tree Algorithms
1. NegaMax
2. Alpha-beta enhancement
 - Move Ordering: iterative deepening, transposition table, killer move heuristic, history heuristic
 - Minimal window search: narrowing search window by varying alpha beta. NegScout.
3. (Selectivity Search with DFS) Forward pruning method like MultiProb-Cut to cutoff unpromising branches
4. BFS approach
 - Monte Carlo Tree Search (MCTS)
 - Memory-enhanced Test Driver (MTD)

### Parallelism in Game Tree Search

1. ABDADA uses shared hast table  to store information about node in tree without causing communication overhead.
2. Parallel Alpha-beta works by splitting search trees into sub-search trees. Provides maximum
   optimization by partition tree at width or depth. Hard to implement
3. Principal Variation Search (PVS) treats each node as a thread. Solve data dependency by running the
   first node among any siblings then run the remaining siblings in parallel
4. YBWC and Jamboree runs a recursive algorithm that runs first node in siblings first before
   spawning remaining siblings. 
5. DTS (Dynamic Tree Search) is the best performing for symmetric multiprocessor
6. NegaScout is better variation of PVS

### Conclusion
1. YBWC is best choice because of speedup and also simplicity to implement
2. For sequential-based algorithm, alpha beta with minimax is the best

## A comparison of some parallel game-tree search algorithms

### Parallel tree search algorithm

1. Measures speedup and efficiency = speedup / no of processors
2. Efficiency is the ratio between total computation time / (total computation time + total
   communication time)
3. Failure to achieve perfect efficiency:
 - starvation loss: processors sitting idle waiting for work
 - interference loss: time spent waiting for shared resources
 - speculative loss: time spent performing unnecessary work such as determining what work is
 necessary

### Alpha-Beta
1. The order in which children of the node are expanded will affect performance of alpha-beta. 
2. Rate node as critical nodes which when expanded in order of increasng value achieve maximum
   cutoff
3. Mandatory work first algorithm to rank nodes
4. Tree-splitting algorithm using best-first ordering
5. Principal variation is a refined version of the tree-splitting algorithm
6. ER algorithm performs better than PV for deep trees.

## Comparing effect of sorting methods
1. Eldest child sorting works best by sorting top node and eldest child.
2. Type-two sorting also works well by sorting type-2 of mandatory work first


### Potential mobility
1. number of adjacent pairs of opponent's discs and empty squares. Only empty squares that can flip
   opponent disc is considered.

## Best first minimax

Only explore frontier node that is at the end of principal variation with maximum static evaluation
mark.

## Clever Name for a chess bot report

1. Young Brother Wait Concept is used to choose the node that hopefully gives a smaller search
   window
2. Transposition table stores hash key and state of the board

## CS221 Othello Report

### Transposition table
1. Exploit information from previous searches.
2. Store as fixed size hash table
3. Integer hashing method

### History heuristics
1. Update the history table when a good move is reported for a particular table.
2. Used for move ordering

### Bitboard and optmization
1. Store as 4 x 32 = 128 bits for a board
2. One board for each type such as for white and black
3. Faster move generation with bit shifting

### Killer table for move ordering
1. Maintain a set of dynamically-updated tables for move ordering
2. 100 entries to store response to each move by opponent from best to worse

### Devise own data structure for calculating mobility and potential mobility
1. Adjacency table
2. Direction table

## Cuda Chess Bot Final Report

### Basic steps / Progression
1. Minimax easily parallelizable
2. Alpha-beta pruning essentially sequential program
3. Deal with shared game state
 - create and modifies local game state
 - only lock at leaf node

### Final implementation
1. PVsplit with OpenMP for workload balancing

## The Development of a World Class Othello Program

### Searching algorithms
1. Iterative deepening
2. Hash table stores record of positions encountered along with best move
3. Killer table stores linked list of moves 
4. Zero-window search (modified iterative deepening)

### End game search
1. Outcome search (win/lose/draw)
2. Disc count differential

### Evaluation
1. Edge stability
2. Mobility

## Efficiency of Parallel Minimax Algorithm for Game Tree Search

### Parallel computational model of minimax
1. Manager-worker
 - MPI_Gather from worker processors
 - MPI_Reduce, determine best cost function from all worker processes
 - MPI_Bcast, broadcasts best move to all worker processes
2. Asynchronous iterations
3. Combines OpenMP and MPI (hybrid)

## Efficient Parallelization of Alpha-Beta Search HPC Lab Course

### Overhead causes
1. Overhead due to parallel search = searched nodes on N processors / searched nodes on 1 processor
   - 1
2. load imbalance
3. Synchronization and communication

### Better partitionaing scheme for search tree
1. Using iterative deepening, principal variation and sorting to move type
2. Best move is searched first
3. Do not parallelize in cut node
4. PVsplit
5. PVsplit with dynamic load balancing
6. Simultaneous partitioning in multiple nodes
7. Distributed control using Young Brothers Wait 

## Game Tree Search on a Massively Parallel System ?

### Enhancement of sequential version
1. NegaScout with fail soft enhancement
2. Transposition table
3. Heuristics
 - iterative deepening
 - prinicple variation and refutation heuristics
 - killer heuristic
 - history heuristic
 - aspiration search

### Distributed algorithms
1. Young Brother Wait concept

## Parallelizing A Simple Chess Program

### Game tree search
1. Branching factor: average number of out edges per non-leaf node
2. PVsplit is one of the earliest parallelization method for alpha-beta
3. Younger Brothers Wait and Jamboree are clearly superior

## Taxanomy of parallel game tree search

### Alpha-beta based

#### Different types of sequential game-tree searching algorithm
1. Alpha-beta
2. NegaScout
3. PVS

#### Speedup ranking (highest top)
1. Delayed Branch Tree Expansion 350 (n=1000)
2. Young Brothers Wait 142 (n=256)
3. Waycool 101 (n=256)
4. Jamboree 50 (n=512)
5. Dynamic Multiple PV-Split 32 (n=64)
6. ABDADA 15.85 (n=32)
7. Key Node 12.57 (n=20)
8. Dynamic Tree Splitting 8.81 (n=16)

### Other search paradigms for parallel game-tree search
1. Evaluate-Refute (ER) performs better than PV split

## Applications of Artificial Intelligence and Machine Learning in Othello

### Static Evaluation

#### Features

#### Game stages
1. Importance of features can change depending on stage of the game
2. Estimated using number of pieces in the game

### Search algorithms and data structure
1. NegaScout (enhancement of alpha-beta pruning) works well for bigger depth
2. MTF(f) more efficient than alpha-beta and outperforms NegaScout but relies heavily on
   transposition table

### Bitboards
1. 2 64-bit bitstrings, one for each color.

## Parallel Game Tree Search Taiwan

### Comments on parallelization
1. Synchronization: effcient to broadcast a message
2. Lockless transposition table
3. Global transposition table vs distributed transposition table
4. Load balancing
 - Ratio between largest work on a processor and the lightest work on another processor
5. Speed-up factor
 - ratio between parallel version with a given number of processors and baseline version
 - super-linear speed-up: achieve N speedup with less than N processors

### Super-linear speed-up
1. Must not enumerate all possibilities to achieve super-linear speed-up

### Parallel alpha-beta search
1. Principle variation (PV split): global synchronization model of parallelism
2. Young Brothers Wait Concept (YBWC): client-server model of parallelism
3. Dynamic Tree Splitting (DTS): peer-to-peer model of parallelism

### Classification of nodes
1. Type 1: Principle variation
 - nodes in the leftmost branch
 - needed to be searched first. Then the rest can be searched in parallel
2. Type 2: Cut nodes
 - children of type1 and type3
 - not wise to parallelize children of cut node
3. Type 3: All nodes
 - first branch of a cut node
 - all children of an all node need to be explored
 - search all the children in parallel

### Memory issues
1. Local data: such as current depth, current best move
2. Hash information
3. Distributed memory model
 - maintain own data in private memory area
 - using message passing to probe hash entry
 - slow response time. coding is easy
4. Shared memory model
 - overhead in locking
 - fast response time

## Parallel Chess Searching & Bitboard

### Game Trees And Searching
1. Branching factor = number of legal moves in a node 
2. NegaMax
3. Alpha-beta

### Search algorithm improvement
1. Aspiration window
 - Choosing a smaller range for alpha beta to trick children we already have a good value
2. Transposition / Refutation table
 - avoid expensive searches of positions that have been searched before
 - use for move ordering
 - Zobrist hashing
3. Improve move ordering
 - killer heuristic
 - history heuristic
 - using evaluation function
 - using transposition table
4. Iterative deepening on shallower depths help to build heuristics
5. Principle variation search
6. Null move pruning
 - checks for if doing nothing is still better

### Data Structure
1. Need to focus on ease of:
 - generation of legal moves of a position
 - generation of child positions from a legal move and a parent position
 - evalaution of a position
2. Bitboard is best for legal move generation and evaluation

### Parallel Searching

#### Main problems
1. Dividing work so that all processors are doing useful work
2. Minimize the time processors doing nothing during startup
3. Minimize waste when determining splitting of work
4. Minimize wastage when combining results

#### Parallel Alpha-Beta
1. Searching different subtrees in parallel
2. Be careful not to split at cut node to prevent unnecessary search
3. Reduce time splitting
4. Handling global data structure issue
5. Divide nodes into type PV, CUT and ALL. Sequential search for type I
6. Younger Brothers Wait Concept embrace these types

### Global data structures
1. Use a global hash table in shared memory with error-checking instead of locking
2. Killer heuristics are kept local
3. History heuristics kept global

### Conclusion
1. Tree size has linear effect

## Parallel Search of Narrow Game Tree

### Parallel Alpha-Beta Game Tree Search
1. Work granularity: refers to how much actual work is completed by the algorithm between points of
   interaction. Coarsed-grained parallelism or high granularity work is preferable
2. Load balancing
 - degree of parallelism: amount of parallel work available. when degree of parallelism is less than
 number of processors available. Some processor receive no work and is starved.
 - uneven distribution of work causing some processors to be stragglers. other processors forced to
 wait for it to synchronize
 - preempt or further divide work if there is any idle processor
3. Search overhead
 - lack of timely information about cutoff and window results 
4. Synchronization overhead
 - algorithm forces a searcher to wait for another searcher to finish. occur when synchronization
 used to gather information to prevent search overhead
5. Communication overhead
 - cause by exchange of data using locks to coordinate shared access. 

### PV-split based
1. Principle variation split
2. Dynamic principle variation split
3. Works best for small number of processors and trees with high branching factor
4. Depth-first search approach reduce storage overhead
5. Centralised parallel search control at split node

### Zugzwang approach
1. Distribute the parallel search control
2. Younger Brother Wait: the first ordered subtree must be searched first before splitting. Avoid
   search overhead only if best move ordering
3. Helpful master: master of a split node waiting for result can decided to assign itself to help a
   searcher
4. Reduces synchronization fan-in at split nodes and avoid bottleneck of single split node algorithm
5. However, create more synchronization points and frequent interactions between searchers may
   result in low granularity parallelism

### Delayed Branching Tree Expansion 
1. Multiple split nodes, non DFS parallel alpha-beta algorithm
2. Leftmost-first split node selection
3. Explore fine-grained component parallelism and coarse-grained search parallelism through tree
   decomposition
4. Works best
