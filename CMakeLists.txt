cmake_minimum_required(VERSION 3.25)
project(Programming)

set(CMAKE_CXX_STANDARD 14)

add_executable(Programming
        Day1/vectorSTL.cpp Day1/dequeSTL.cpp "Day1/First Unique Character in a String.cpp" "Day1/Kth Largest Element.cpp" "Day1/One Integer.cpp" "Day1/Maximum Score From Removing Stones.cpp" "Day1/Find K Closest Elements.cpp" "Day1/Find K Closest Elements using Priority Queue.cpp" "Day1/Distinct Candies.cpp" "Day1/Bulls and Cows.cpp" "Day1/Smallest Range Covering Elements from K Lists.cpp" "Day2/Odd or Even.cpp" "Day2/Bit Manupulations.cpp" "Day2/Two Power.cpp" "Day2/Four Power.cpp" "Day2/Decode XORed Array.cpp" "Day2/Decimal to Binary.cpp" "Day2/Sort Integers by The Number of 1 Bits.cpp" "Day2/Longest Consecutive Run of 1s in Binary.cpp" "Day2/Hamming Distance.cpp" "Day2/Unique Number-I.cpp" "Day2/Unique Number-II.cpp" "Day2/Unique Numbers -III.cpp" Day2/Subsets.cpp Day2/subsets--02.cpp "Day3/Score After Flipping Matrix.cpp" "Day3/Triples with Bitwise AND Equal To Zero .cpp" "Day3/Bitwise AND of Range of Numbers.cpp" "Day3/Total Hamming Distance.cpp" Day3/tsp.cpp Practicing/tsp.cpp Day3/Tsp_DP.cpp "Day3/Decode Permutation.cpp" Day4/POW.cpp "Day4/magic of the locker.cpp" "Day4/strange function.cpp" "Day4/matrix exponentiation fibnocci.cpp" "Day4/mat exp fib.cpp" Day4/seq.cpp "Day5-Pegion Hole Principle/div subs.cpp" "Day5-Pegion Hole Principle/decreasing sequence.cpp" "Day5-Pegion Hole Principle/grey similar code.cpp" "Day5-Pegion Hole Principle/Holiday code.cpp" "Day5-Pegion Hole Principle/holi spoj.cpp" "Day5-Pegion Hole Principle/test.cpp" "Day5-Pegion Hole Principle/Subarray Sum Divisible by N.cpp" "Day5-Pegion Hole Principle/Bob and Impossible Calculation .cpp" "Day6/Bob and Palindromes .cpp" "Day6/Second Player.cpp" "Day6/Total Number of Divisors Till N code.cpp" Day6/Divisibility.cpp Day6/primeSieve.cpp "Day6/Prime Factors.cpp" "Day7/Alice and Candies.cpp" "Day7/Prime Sum.cpp" "Day7/Closest Divisors.cpp" "Day8/Gifts and Boxes.cpp" Day8/Math.cpp "Day8/Extended Euclidean Code.cpp" "Day8/Greatest Common Divisor.cpp" "Day8/ Coprime Divisor .cpp" "Day8/Alice Studies Informatics.cpp" "Day8/Row GCD.cpp" "Sliding Window Techniques/nCr.cpp" "Sliding Window Techniques/Housing Problem.cpp" "Sliding Window Techniques/Longest Substring Without Repeating Characters .cpp" "Sliding Window Techniques/Minimum Window Substring .cpp" "Sliding Window Techniques/Sliding Window Maximum .cpp" "Sorting Techniques/Merge Sort.cpp" "Sorting Techniques/Inversion Count.cpp" "Sorting Techniques/Quick Sort.cpp" "Sorting Techniques/Kth Largest Element in an Array .cpp" "Sorting Techniques/Lexicographically Smallest String .cpp" "Sorting Techniques/Sparse Search.cpp" "Sorting Techniques/Staircase Search.cpp" "Sorting Techniques/ICPC Standings.cpp" "Sorting Techniques/Sorting Subarray.cpp" "Day-11 Binary Search/BinarySearch.cpp" "Day-11 Binary Search/Frequency Count.cpp" "Day-11 Binary Search/Search in Rotated Sorted Array.cpp" "Day-11 Binary Search/Square Roots.cpp" "Day-11 Binary Search/AGGRCOW - Aggressive cows.cpp" "Sliding Window Techniques/Count the subarrays having product less than k.cpp" "Day-11 Binary Search/Game of Greeds.cpp" "Day-11 Binary Search/Reading Books.cpp" "Recursion/Ladders Code.cpp" "Recursion/Count Subsets.cpp" "Recursion/Generate Parentheses .cpp" "Recursion/Letter Combinations of a Phone Number.cpp" Recursion/Permutations.cpp "Recursion/N-Queens .cpp" "Recursion/Sudoku Solver.cpp" "Recursion/Game of Coins.cpp" "Linked Lists/LinkedLists.cpp" "Linked Lists/K Reverse.cpp" "Linked Lists/Sort 2 Sorted Linked Lists.cpp" "Linked Lists/Middle Element.cpp" "Linked Lists/Merge Sort for Linked List.cpp" "Linked Lists/Detect Cycle.cpp" "Stacks, Queues and Deques/Balanced Paranthesis.cpp" "Stacks, Queues and Deques/Redundant Paranthesis Code.cpp" "Stacks, Queues and Deques/First Non-Repeating Character.cpp" "Stacks, Queues and Deques/Simplify Path.cpp" "Stacks, Queues and Deques/Stock Span Problem.cpp" "Binary Trees/Level Order.cpp" "Binary Trees/Level Order Build.cpp" "Binary Trees/Tree Diameter.cpp" "Binary Trees/Replace with Descendent Sum.cpp" "Binary Trees/Height of BT.cpp" "Binary Trees/Height Balanced.cpp" "Binary Trees/Max Subset Sum Tree.cpp" "Binary Trees/Nodes at Distance K.cpp" "Binary Trees/Vertical Order Print.cpp" "Binary Trees/Left View.cpp" "Binary Trees/Nodes At Distance K Versio2.cpp" "Binary Trees/Siblings Swap!.cpp" "Binary Search Trees/BST Creation.cpp" "Binary Search Trees/Minimum Height BST from Sorted Array.cpp" "Binary Search Trees/Searching Closest Element.cpp" "LeetCode daily Questions/Find Eventual Safe Nodes.cpp" "Binary Search Trees/Tree to LinkedList.cpp" "Binary Search Trees/Inorder Successor.cpp" "Binary Search Trees/Is BST.cpp" "Binary Search Trees/Hoffman Decoding.cpp" "LeetCode daily Questions/Course Schedule.cpp" "Binary Search Trees/Shortest Tree Path.cpp" "Priority Queues/Priority Queues.cpp" "Priority Queues/Finding Cabs.cpp" "Priority Queues/Merging Ropes.cpp" "Priority Queues/Running Median.cpp" "Priority Queues/Sort K Sorted Arrays.cpp" "Hashing Techniques/Common Elements.cpp" "Hashing Techniques/Triplets in GP.cpp" "Hashing Techniques/Count Rectangles.cpp" "Hashing Techniques/Count Right Angle Triangles.cpp" "Hashing Techniques/Anagrams in Substrings.cpp" "Hashing Techniques/The Quick Brown Fox.cpp" "Hashing Techniques/Longest K Sum Subarray.cpp" "Tries/Prefix Trie.cpp" DESHAW/Question1.cpp DESHAW/Question3.cpp Graphs/BFS.cpp "Graphs/Shortest Path Using BFS.cpp" Graphs/DFS.cpp "Graphs/Check Cycle in Undirected Graph.cpp" "Graphs/Dijkshtra's Shortest Distance.cpp" "Graphs/Board Game.cpp" "Graphs/Shortest Grid Path.cpp" "Graphs/Shortest grid Path with Dijkshtra's.cpp" "Graphs/Largest island.cpp" "Graphs/Astonaut Pairs.cpp" "Graphs/Longest Graph Sequence DP.cpp" "Graphs/Median Path.cpp" "DP-I/N-K Ladders.cpp" "DP-I/Coin Change.cpp" "DP-I/Rod Cutting Problem.cpp" "DP-I/Min Array Jumps.cpp" "DP-I/Frog's Minimum Cost-I.cpp" "DP-I/Maximum Non Adjacent Sum.cpp" "DP-I/Longest Increasing Subsequence.cpp" "DP-I/Box Stacking.cpp" "DP-I/Count BST'S.cpp" "DP-II/Longest Common Subsequence.cpp" "DP-II/Selling Wines.cpp" "DP-II/Counting Subsequences.cpp" "DP-II/Count Subsets That Are Divisible by N.cpp" "DP-II/Longest Repeating Subsequence.cpp" "DP-II/KnapSack Problem.cpp" "Recursion/Oxygen Limit.cpp" DESHAW/PQ1.cpp DESHAW/PQ2.cpp "DESHAW/Max Toys.cpp" "Recursion/Tower of Honoi.cpp" "Parthiv/Tower of Stones.cpp" "Parthiv/Count Greater or Lesse.cpp" Parthiv/Inventory.cpp "Parthiv/Minimum Jewels Stolen.cpp" "Parthiv/Get Minimum Steps.cpp" "Parthiv/Max Sum of Pairs.cpp" "Parthiv/MIn Cost of Servers.cpp" "Parthiv/Queries and Array.cpp" "Parthiv/Get Anagram Period.cpp" "Parthiv/Select Stocks.cpp" "My Exams/Bitonic Arrays.cpp" "My Exams/Hacker Question.cpp" "Directed Graphs and SCC's/Topoligical Sort.cpp" "Directed Graphs and SCC's/Restricted Permutation.cpp" "Directed Graphs and SCC's/Game Routes.cpp" "Directed Graphs and SCC's/Kosaraju Algorithm to Find SCC.cpp" "Shortest Path Algorithms/Dijkshtra's Algorithm.cpp" "Shortest Path Algorithms/Delay Time in Network.cpp" "Shortest Path Algorithms/Dijkshtra's Shortest Path.cpp" "Shortest Path Algorithms/Come Back Quickly.cpp" "Shortest Path Algorithms/BellMan Ford.cpp" "Parthiv/Maximum Profit.cpp" "Parthiv/Valid Keys.cpp" "Parthiv/Maximum Profit Bottom Up.cpp" "Parthiv/Valid Keys Sieve Method.cpp" "Shortest Path Algorithms/Floyed Warshall Algorithm.cpp" "Shortest Path Algorithms/Cheapest Flight with K Stops.cpp" "Parthiv/Minimum Days to Buy All Stocks.cpp" "My Exams/Min Steps to Put 1 Stone.cpp" "My Exams/Atari Kills.cpp" "Pramod/Max Volume.cpp" Pramod/getCount.cpp "Pramod/Max Weight.cpp" "Pramod/Max Vol Bottom Up.cpp" "Gaman/Segments Question.cpp" "Gaman/Subarray Maximisation.cpp" "Parthiv/Get Minimum Health.cpp"
        "Gaman/LRU Cache.cpp"
        "Gaman/sonali toys.cpp"
        "Gaman/Knowlede Tranfer.cpp"
        Gaman/minDays.cpp
        "CSES/Graph Problems/Labyrinth.cpp"
        "CSES/Graph Problems/Labyrinth--02.cpp"
        "CSES/Graph Problems/building_roads.cpp"
        "CSES/Graph Problems/message_route.cpp"
        "Arcesium/House distancing.cpp"
        "Arcesium/Is Winnable.cpp"
        Arcesium/isWinnableDP.cpp
        "Arcesium/Beatiful Garden.cpp"
        "Arcesium/Match Making.cpp"
        Arcesium/dechipering.cpp
        "CSES/Dynamic Programming/dice_combinations.cpp"
        "CSES/Dynamic Programming/minimising_coins.cpp"
        "CSES/Dynamic Programming/coin_combinations1.cpp"
        "CSES/Dynamic Programming/coin_combinations2.cpp"
        "CSES/Dynamic Programming/removing_digits.cpp"
        "Day-11 Binary Search/Koko Eating Bananas.cpp"
        test/test1.cpp
        test/test2.cpp
        "DP-I/word break.cpp"
        "CSES/Dynamic Programming/gridPaths.cpp"
        "CSES/Dynamic Programming/Book Shop.cpp"
        "CSES/Dynamic Programming/Array Description.cpp"
        "Amazon/Asteroids Colisions.cpp"
        "Amazon/Best Time To Buy and Sell Stock With Cooldown.cpp"
        "Amazon/Max Sum No Consecutive Subset.cpp"
        "Amazon/Construction of BST From PostOrder.cpp"
        "Binary Search Trees/Lowest Common Ancestor.cpp"
        "Graphs/Prims MST.cpp"
        "Graphs/Krushkal's MST.cpp"
        "Sorting Techniques/Radix Sort.cpp"
        CHECK/shit.cpp
        "CSES/Graph Problems/building_teams.cpp"
        "CSES/Sorting and Searching/Sum of Two Values.cpp"
        "Amazon/Count Of Fautly Servers.cpp"
        "Amazon/pth Factor.cpp"
        "My Exams/Maximal Square.cpp"
        Amazon/test.cpp
        "Sorting Techniques/Insertion Sort.cpp")
