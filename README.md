# Chess Movegen
State of the art comparison of chess sliding piece algorithms.
Prints memory consumption for each algorithm
Prints which operation needs to exist in hardware for maximum performance. Inline versions available (no lookup table used)

## Currently compares single and multithreaded code for these algorithms:
| Name | Performance [MQueens/s] |
| ------------- | ------------- |
| Pext constexpr                    | 13042.472180
| Black Magic BB - Fixed shift      | 9782.268111 
| Magic BB - Fancy variable shift   | 9651.382716 
| Hyperbola Quintessence o^(o-2r)   | 8780.896063 
| Rotated Bitboards                 | 7263.823231 
| Kindergarten                      | 7150.023641 
| Obstruction Difference            | 6570.545938 
| Pext Emulated                     | 5993.523128 
| Obstruction Difference Inline     | 5265.051466 
| Magic BB - Plain                  | 5211.726384 
| Leorik Inline                     | 5179.507529 
| Leorik                            | 5149.437507 
| Hyperbola Quintessence Inline     | 4687.381870 
| SBAMG o^(o-3cbn)                  | 4662.157486 
| SBAMG Inline                      | 4500.221382 
| HyperCube                         | 4428.498774 
| Classical Bob-Mike                | 3776.684637 
| Slide Arithmetic Inline           | 3633.318668 
| Slide Arithmetic                  | 3483.268699 
| Exploding Bitboards               | 3378.966986 
| QBBEngine                         | 3219.081103 
| Kogge-Stone                       | 2728.609026 
| SISSY Bitboards                   | 2542.976299 
| Reference (Switch Lookup)         | 2514.003787 
| Dumb7 Fill                        | 2342.216757 


# Special Modes
Some of the above algorithms have 0kb lookup modes where values are calculated at runtime without any lookups at all.
Some of the above algorithms have a templated position parameter to have a forceinlined version of these lookups available! 


# Build
- Linux: make
- Windows: use Visual Studio Solution

# How to use
Just copy and paste the .hpp file you would like to use in your own chess engine. Now you are done. No initialisation etc. needed (happens during compiletime)
```
namespace Lookup = Chess_Lookup::Lookup_Hyper;
Lookup::Prepare(occ);
uint64_t attacks = Lookup::Queen(sq);
```
# Example Result:
```
AMD Ryzen 9 5950X 16-Core Processor

Megalooks Known Positions/s:
Name                               Performance [MQueens/s]       Tablesize           Dependencies             Template  Author                                       Reference
Exploding Bitboards                367.915260                    768     [6kb]       imul64                   no        Harald L��en                                  http://www.open-aurec.com/wbforum/viewtopic.php?f=4&t=4523&start=80
Reference (Switch Lookup)          285.862449                    0       [0kb]       none                     yes       Daniel Inf�hr (dangi12012)                   http://www.talkchess.com/forum3/viewtopic.php?f=7&t=78235&p=907362&hilit=espresso#p907362
Pext Emulated                      729.725600                    107904  [843kb]     none                     no        Zach Wegner                                  https://randombit.net/bitbashing/posts/haswell_bit_permutations.html
Dumb7 Fill                         273.649635                    0       [0kb]       none                     no        Gunnar Andersson                             https://www.chessprogramming.org/Dumb7Fill
Kogge-Stone                        424.687059                    0       [0kb]       none                     no        Peter M. Kogge, Harold S. Stone              https://www.chessprogramming.org/Kogge-Stone_Algorithm
Rotated Bitboards                  488.166166                    1848    [14kb]      none                     no        Robert Hyatt                                 https://www.chessprogramming.org/Rotated_Bitboards
QBBEngine                          400.263173                    0       [0kb]       countr_zero, countl_zero yes       Fabio Gobbato                                https://www.chessprogramming.org/QBBEngine
Classical Bob-Mike                 591.863176                    1024    [8kb]       countr_zero, countl_zero yes       Robert Hyatt and Michael Sherwin             https://www.chessprogramming.org/Classical_Approach
Leorik                             749.103125                    128     [1kb]       countl_zero              no        Thomas Jahn (lithander)                      https://github.com/lithander/MinimalChessEngine
Leorik Inline                      790.777557                    0       [0kb]       countl_zero              no        Thomas Jahn (lithander)                      https://github.com/lithander/MinimalChessEngine
Obstruction Difference             794.436955                    768     [6kb]       countl_zero              no        Michael Hoffmann                             http://www.talkchess.com/forum3/viewtopic.php?t=29087
Obstruction Difference Inline      789.721771                    0       [0kb]       countl_zero              yes       Michael Hoffmann                             http://www.talkchess.com/forum3/viewtopic.php?t=29087
Slide Arithmetic                   543.409504                    256     [2kb]       bzhi_u64, blsmsk_u64     no        Jakob Progsch and Daniel Inf�hr              http://www.talkchess.com/forum3/viewtopic.php?f=7&t=78693&p=914767&hilit=SlideArithm#p914767
Slide Arithmetic Inline            547.457743                    0       [0kb]       bzhi_u64, blsmsk_u64     no        Jakob Progsch and Daniel Inf�hr              http://www.talkchess.com/forum3/viewtopic.php?f=7&t=78693&p=914767&hilit=SlideArithm#p914767
SBAMG o^(o-3cbn)                   764.555220                    576     [4kb]       countl_zero, bswap       yes       Syed Fahad                                   http://www.talkchess.com/forum3/viewtopic.php?t=59845
SBAMG Inline                       732.242825                    0       [0kb]       countl_zero, bswap       yes       Syed Fahad and Daniel Inf�hr                 http://www.talkchess.com/forum3/viewtopic.php?t=59845
Hyperbola Quintessence o^(o-2r)    1046.699136                   256     [2kb]       bswap                    no        Ryan Mack                                    https://www.chessprogramming.org/Hyperbola_Quintessence
Hyperbola Quintessence Inline      680.980740                    0       [0kb]       bswap                    yes       Ryan Mack                                    https://www.chessprogramming.org/Hyperbola_Quintessence
Kindergarten                       1173.254921                   16640   [130kb]     imul64                   no        Urban Koistinen                              https://www.chessprogramming.org/Kindergarten_Bitboards
SISSY Bitboards                    374.432136                    180416  [1409kb]    none                     no        Michael Sherwin                              http://www.talkchess.com/forum3/viewtopic.php?f=7&t=73083
Magic BB - Fancy variable shift    1458.932198                   93376   [729kb]     imul64                   yes       Pradu Kannan                                 https://www.chessprogramming.org/Magic_Bitboards#Fancy
Magic BB - Plain                   1170.833798                   295168  [2306kb]    imul64                   no        Lasse Hansen                                 https://www.chessprogramming.org/Magic_Bitboards#Plain
Black Magic BB - Fixed shift       1618.266180                   88891   [694kb]     imul64                   no        Onno Garms and Volker Annuss                 https://www.chessprogramming.org/Magic_Bitboards#Fixed_shift_Fancy
Pext constexpr                     2478.919501                   107904  [843kb]     pext_u64                 yes       Zach Wegner                                  https://www.chessprogramming.org/BMI2#PEXTBitboards
HyperCube                          307.828611                    107680  [841kb]     none                     yes       Daniel Inf�hr (dangi12012)                   http://www.talkchess.com/forum3/viewtopic.php?f=7&t=79004&p=916723&hilit=hypercube#p916723
```


