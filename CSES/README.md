# **CSES**

# **Graph Algorithms**
|  Name 	            | By Myself |  Tag  |   Interesting Ideas  |  Approach / Idea 	|
|          :-:	        |    ---	|  ---	|---	|---	|
|  **Counting Rooms**	|    Yes 	|  `Connected Component`	|   	|   	|
|  **Labyrinth** 	    |    Yes    | `BFS` <br> `Path Finding` |   	|   	|
|  **Building Roads**   |    Yes	|  `Connected Component` 	|   	|   	|
|  **Message Route** 	|    Yes	| `Dijkstra` <br> `Path Finding` |  |   	|
|  **Building Teams**   |    Yes    |   `Bipartite Check`     |   	|   	|
|  **Round Trip** 	    |    Yes    | `Cycle Check` <br> `Print any cycle`      |   	|   	|
|  **Monsters** 	    |    Yes    | `BFS` <br> `Path Finding`  | **`memset`** is faster than plain loop |   	|
|  **Shortest Routes I** 	|  Yes 	|  `Dijkstra` 	             |  **`Dijkstra optimization`** by checking **if current distance is the minimum one or not** 	|   	|
|  **Shortest Routes II**	|  Yes 	|  `Floyd Warshall`  |   	|   	|
|  **High Score** 	    |     Yes   |  `Bellman Ford` <br> `Negative Cycle`	|  (1) Finding the nodes that are part of negative cycle using Bellman Ford <br> (2) In a **`directed graph`** , the efficient way to check if a node can be reached from multiple nodes is dfs from **`reverse graph`** |  We need to know if there is a cycle in the path a->b <br> Now , we find all the nodes that are part of the negative cycle in the original graph . Then we have to check if there is a path from these negative cycle nodes to b <br> To do this efficiently , my idea is to reverse the graph and check if there exists a path from b to any of these nodes 	|
|  **Flight Discount** 	|   **`No`**   | `Dijkstra` <br> `DP` 	|   **`DP with Dijkstra`** 	|   	|
|  **Cycle Finding**	|   	        |   	|   	|   	|
|  **Flight Routes** 	|   **`No`**	| `Dijsktra` <br> `kth shortest path` |  `Optimal updating` using `sorting` when **tracking multimple maximum / minimum** 	|   	|
|  **Round Trip II** 	|   	|   	|   	|   	|
|  **Course Schedule** 	|   	|   	|   	|   	|
|  **Longest Flight Route** |   Yes	|  `Longest Path` <br> `DAG` <br> `DP` | (1) **Longest Path for DAG** <br> (2) **DP with DAG**  (**`DAG`** has nice **DP properties**)	|   	|
|  **Game Routes** 	|   Yes	|  `DAG` <br> `DP` 	|  **DP with DAG** 	|   	|
|  **Investigation** 	|   **`Almost Yes`**	|  `Dijkstra` <br> `DP` 	|   	| Update to new value when new shortest path is found , otherwise add to exisitng one    	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|
|   	|   	|   	|   	|   	|


# **Dynamic Programming**

|  Name 	| By Myself  	| Tag  	|  Analysis / Approach 	|
|---	|---	|---	|---	|
|  **`Dice Combinations`**  |   Yes	| Basic DP	| Coin Change **number of ways**  	|
|  **`Minimizing Coins`**	|  Yes 	| Coin Change  	|   Coin Change **minimum number of coins**	|
|   **`Coin Combinations I`**	|  Yes 	| Coin Change  |  Coin Change **number of ways** 	|
|   **`Coin Combinations II`**	|  **`No`** 	| Coin Change  |  Coin Change _**ordered**_ **number of ways** 	|
|  **`Removing Digits`** 	|  Yes 	|   Basic DP	|  Easy Transition 	| 
|  **`Grid Paths`**	|  Yes 	|  2D DP 	|  Easy Transition **(Collection DP)** + Handle Corner Case	|
|  **`Book Shop`**	|   Yes	|  Knapsack 	|  Recursive DP will get **`TLE`** 	| 
|  **`Array Description`** 	|   Yes	|  Case Analysis DP <br> **`MEDIUM`**	|   If first position is unknown and next position is also unknow , there are `M` possible option . Otherwise there are only 3 options 	|
|  **`Edit Distance`** 	|   Yes	|  Edit Distance 	|  Corner Case : if `i`<0 or `j`<0 add remaining length of other 	|
|   **`Rectangle Cutting`**	|   	|   	|   	|
|  **`Money Sums`** 	|  **`No`** 	|  Coin Change Variation <br> **`MEDIUM`** 	|  **Reverse iteration** 	|
|  **`Removal Game`**	|   	|   	|   	|
|   **`Two Sets II`**	|  Yes	|  Partition  	|   **Minimum Difference** Partition	|
|  **`Increasing Subsequence`** 	|  Yes 	|  LIS <br> **`MEDIUM`** 	|  Approach 1 : **`Binary Search`** <br> Approach 2 : **`Segment Tree / Fenweick Tree`** 	|
|  **`Projects`** 	|   	|   	|   	|