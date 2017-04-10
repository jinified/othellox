# Project 2: OthelloX
Given a current board position , assess the best choice for a next move leveraging
on openMP parallelization. Play on mxn board.

## What do they want ? (10 - 20 pages)
1. Focus on parallelization techniques
2. Outline techniques used and contribution of each tecnique with respect to speedup results.
3. Reflect how program scales with program size.

## Program I/O
1. Input: input board file, evaluation parameters file
2. Output: set of best next moves i.e {d3, c4, e6, f5}, number of boards accessed,  depth of boards,
   elapsed time

## Task
1. How to expand problem size ? size of board, depth of the search  Should be able to full search on
   6x6 and 8x10. 
2. Write about board storage techniques
3. Quantitative evaluation used to evaluate code
4. Write on how to handle various challenges of parallel computation (aggregation, load balancing,
   commumincation/computation)
5. Tabulate and chart the results when changing the size of the problem and reflect on reasons.

## References

### Parallelizing Game Tree Search

1. [Fernando Silva Parallelizing Min Max](http://www.dcc.fc.up.pt/~fds/aulas/PPD/1314/project3.html)
2. [Efficiency of Parallel Minmax](https://pdfs.semanticscholar.org/04ad/040775ee4208b5babd68e87949409d3a2286.pdf)
3. [Parallel Othello AI](http://rnvarma.github.io/418_final_report.pdf)
4. [CMU: Parallel Alpha-Beta for chess bots](http://www.cs.cmu.edu/afs/cs/academic/class/15418-s12/www/competition/www.contrib.andrew.cmu.edu/~jvirdo/418-project.html)
5. [Parallel Alpha-Beta TUM](http://wwwi10.lrr.in.tum.de/~gerndt/home/Teaching/EfficientHPCProgramming/Assignment7.html)
6. [Efficient Parallelization of Alpha-Beta Search HPC Lab Course](http://wwwi10.lrr.in.tum.de/~gerndt/home/Teaching/EfficientHPCProgramming/ParalleleSuche.pdf)
7. [Game Tree Search on Massively Parallel System](https://pdfs.semanticscholar.org/12c8/0362791b9727165cf7d6d63c19033ed7ece2.pdf)
8. [Cuda Chess Bot](https://manikpanwar.github.io/CudaChessBot-website/15418FinalReport.pdf)
9. [Parallelizing a simple chess program](http://iacoma.cs.uiuc.edu/~greskamp/pdfs/412.pdf)
10. [Parallel Alpha-Beta Pruning of Game Decision Trees](https://students.cs.byu.edu/~snell/Classes/CS584/projectsF99/steele/report.html)
11. [Parallel game tree search algorithms comparison](https://www.researchgate.net/profile/Raphael_Finkel/publication/2813087_A_comparison_of_some_parallel_game-tree_search_algorithms_Revised_version/links/0c960531a10c97da04000000.pdf)
12. [Comparative study of game tree searching methods](https://thesai.org/Downloads/Volume5No5/Paper_10-A_Comparative_Study_of_Game_Tree_Searching_Methods.pdf)
13. [Parallel Game Tree Search taiwan](http://www.iis.sinica.edu.tw/~tshsu/tcg/2013/slides/slide11.pdf)
14. [CS758: Parallel Game AI](http://pages.cs.wisc.edu/~markhill/cs758/Fall2012/wiki/index.php?n=Main.Homework3)
15. [CS221: Othello Report](http://ai.stanford.edu/~chuongdo/papers/demosthenes.pdf)
16. [Parallel Search Chess programming wiki](https://chessprogramming.wikispaces.com/Parallel+Search)
17. [Memory vs Search in games](https://breukerd.home.xs4all.nl/thesis/)
18. [The history heuristic and alpha beta search enhancement in practice](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.56.9124&rep=rep1&type=pdf)
19. [Analysis of speedup in distributed algorithms](ftp://ftp.cs.wisc.edu/pub/techreports/1981/TR431.pdf)
20. [Parallizing  a simple chess program](http://iacoma.cs.uiuc.edu/~greskamp/pdfs/412.pdf)
21. [Parallel Chess Searching and Bitboard](http://etd.dtu.dk/thesis/154796/imm3267.pdf)
22. [A Taxonomy of Game Tree Search Algorithms](http://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.47.8438&rep=rep1&type=pdf)
23. [Scalability and Parallelization of Monte-Carlo Tree Search](https://hal.inria.fr/file/index/docid/512854/filename/newcluster.pdf)
24. [Is parallel programming hard ?](https://www.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook-e1p.pdf)

### OpenMP / MPI & Parallel Programming Techniques
1. [OpenMP in 30 minutes](http://www.linux-mag.com/id/4609/)
2. [Using OpenMP by Barbara Chapman](http://lib.mdp.ac.id/ebook/Karya%20Umum/Portable_Shared_Memory_Parallel_Programming.pdf)
3. [Introduction to Parallel Programming, Lawrence Livermore National Library](https://computing.llnl.gov/tutorials/parallel_comp/)
4. [Learning OpenMP Framework with GCC by IBM](https://www.ibm.com/developerworks/aix/library/au-aix-openmp-framework/)
5. [OpenMP Lawrence Livermore National Library](https://computing.llnl.gov/tutorials/openMP/)
6. [MPI tutorials](http://mpitutorial.com/tutorials/)
7. [MPI Lawrence Livermore National Library](https://computing.llnl.gov/tutorials/mpi/)
8. [MPI Tutorial UCLA](https://idre.ucla.edu/sites/default/files/mpi-2013-02-13.pdf?x83242)
9. [Open MPI tutorial](https://www.open-mpi.org/papers/sc-2009/jjhursey-iu-booth.pdf)
10. [A Hands on introduction to OpenMP](http://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf)
11. [OpenMP by example](http://sc.tamu.edu/shortcourses/SC-openmp/OpenMPSlides_tamu_sc.pdf)
12. [Parallel programming in c with MPI and OpenMP](http://epcc.sjtu.edu.cn/wordpress/wp-content/uploads/2013/05/parallel-programming-in-c-with-mpi-and-openmp.pdf)
13. [TUM OpenMP](http://wwwi10.lrr.in.tum.de/~gerndt/home/Teaching/EfficientHPCProgramming/OpenMP.pdf)
14. [Common mistakes in OpenMP](http://wwwi10.lrr.in.tum.de/~gerndt/home/Teaching/EfficientHPCProgramming/CommonMistakesInOpenMPAndHowToAvoidThem.pdf)
15. [TUM MPI](http://wwwi10.lrr.in.tum.de/~gerndt/home/Teaching/EfficientHPCProgramming/MPI.pdf)

### Parallel Programming Design Patterns
1. [Design Patterns for Parallel Programming I](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-189-multicore-programming-primer-january-iap-2007/lecture-notes-and-video/l6-design-patterns-for-parallel-programming-i/)
2. [Design Patterns for Parallel Programming II](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-189-multicore-programming-primer-january-iap-2007/lecture-notes-and-video/l7-design-patterns-for-parallel-programming-ii/)
3. [Performance monitoring and optimizations](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-189-multicore-programming-primer-january-iap-2007/lecture-notes-and-video/l10-performance-monitoring-and-optimizations/)

### Sample code implementations
1. [Minimax in C](https://gist.github.com/MatthewSteel/3158579)
2. [Parallel Alpha Beta for checkers](https://github.com/electrojustin/c_checkers)
3. [Alpha beta pruning MPI](https://github.com/AboorvaDevarajan/Parallel-Checkers-Game)
4. [Parallel Alpha Beta Search chess](https://github.com/spencerwuwu/Parallelized-Mini-Max-Search-and-Alpha-Beta-Pruning)
5. [Parallel Reversi](https://github.com/iroq/ParallelReversi)
6. [Parallel Reversi with MPI](https://github.com/xtrinch/parallel-reversi)
7. [Negamax implementation in c](https://xojoc.pw/dailyprogrammer/173.c)
8. [Bitboard for reversi](https://github.com/rcrr/reversi/blob/master/field_research/code/zebra/bitboard.c)

### Basics
1. [Alpha-beta pruning](https://www.youtube.com/watch?v=xBXHtz4Gbdo)
2. [Minimax & Alpha-Beta Pruning CSCI 6350](https://www.youtube.com/watch?v=J1GoI5WHBto)
3. [Parallelism and selectivity in game tree search](https://www.youtube.com/watch?v=R0L3AuJUkk0)
4. [John Levin Minimax Alpha-Beta Prunin](https://www.youtube.com/watch?v=zp3VMe0Jpf8)

### Performance analysis
1. [Open-mpi FAQS](https://www.open-mpi.org/faq/?category=perftools)
2. [Performance analysis tools Livermore](https://computing.llnl.gov/tutorials/performance_tools/)
3. [HPC Toolkit](http://hpctoolkit.org/slides/hpctoolkit-og15.pdf)
4. [Texas Advanced Computing Centre: Overview of profiling](https://portal.tacc.utexas.edu/documents/13601/1041435/29-Overview_of_Profiling.pdf/84359111-d21a-4618-9d90-ca878c1e37ab)
5. [Intel VTune Amplifier](https://software.intel.com/en-us/articles/profiling-openmp-applications-with-intel-vtune-amplifier-xe)

### Othello
1. [Othello wiki](https://chessprogramming.wikispaces.com/Othello)
2. [Bitboard for games](http://eprints.qut.edu.au/85005/1/__staffhome.qut.edu.au_staffgroupm$_meaton_Desktop_bits-7.pdf)
3. [Othello Evaluation function](http://stackoverflow.com/questions/12334216/othello-evaluation-function)
