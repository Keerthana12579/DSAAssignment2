# DSAAssignment2
# Data Structures Assignment – Question 7
## Hashing and Linear Search for Song IDs

### Problem Statement

A music application stores the following song IDs:

**105, 210, 315, 420, 525, 630, 735, 840**

The objective is to implement a hash table using the **Division Method**, insert the given song IDs, identify and handle collisions, and compare the performance of hashing with linear search.

The assignment also requires analysing the effect of collisions on search performance, calculating the load factor, and comparing the observed performance with the theoretical time complexity of hashing and linear search.

---

## Objectives

1. Implement a hash table using the Division Method.
2. Insert the given song IDs into the hash table.
3. Identify and handle collisions.
4. Search for the given song IDs using hashing.
5. Search for the same song IDs using linear search.
6. Record and compare the number of operations/comparisons.
7. Calculate the load factor of the hash table.
8. Analyse the effect of collisions on search performance.
9. Compare the practical results with theoretical time complexity.
10. Determine whether hashing is suitable for the music application.
### Input Data
The song IDs used in this assignment are:
105, 210, 315, 420, 525, 630, 735, 840
Hashing Method
The Division Method is used for calculating the hash index.
Hash Function
h(K) = K mod m
where:
K = Song ID
m = Hash table size
For this implementation:
Hash table size (m) = 10
Therefore:
h(K) = K mod 10
### Collision Resolution
Linear Probing is used to resolve collisions.
When the calculated position is already occupied, the next available position is searched sequentially.
h_i(K) = (h(K) + i) mod m
where i = 0, 1, 2, ...
### Hash Table Insertion
| Song ID | Initial Hash Value | Final Position | Collision |
| ------: | -----------------: | -------------: | :-------: |
|     105 |                  5 |              5 |     No    |
|     210 |                  0 |              0 |     No    |
|     315 |                  5 |              6 |    Yes    |
|     420 |                  0 |              1 |    Yes    |
|     525 |                  5 |              7 |    Yes    |
|     630 |                  0 |              2 |    Yes    |
|     735 |                  5 |              8 |    Yes    |
|     840 |                  0 |              3 |    Yes    |
Final Hash Table
| Index | Song ID |
| ----: | ------: |
|     0 |     210 |
|     1 |     420 |
|     2 |     630 |
|     3 |     840 |
|     4 |   Empty |
|     5 |     105 |
|     6 |     315 |
|     7 |     525 |
|     8 |     735 |
|     9 |   Empty |
## Collision Analysis
Several song IDs produce the same initial hash value.
For example:
105 mod 10 = 5

315 mod 10 = 5

525 mod 10 = 5

735 mod 10 = 5

Therefore, these values initially map to index 5.

Similarly:

210 mod 10 = 0

420 mod 10 = 0

630 mod 10 = 0

840 mod 10 = 0

These values initially map to index 0.

Linear probing is therefore required to find the next available positions.

Load Factor

The load factor is calculated using:

Load Factor = Number of elements / Hash table size

Here:

Number of elements = 8

Hash table size = 10

Therefore:

Load Factor = 8 / 10
             = 0.8
             = 80%

A load factor of 0.8 means that 80% of the hash table is occupied.

A high load factor can result in more collisions and increase the number of comparisons during search.

## Search Comparison
The song IDs are searched using two methods:
Hashing
## Linear Search

1. Hashing Search

The number of comparisons required for each song ID is:

| Song ID | Positions Checked | Comparisons |
| ------: | ----------------- | ----------: |
|     105 | 5                 |           1 |
|     210 | 0                 |           1 |
|     315 | 5, 6              |           2 |
|     420 | 0, 1              |           2 |
|     525 | 5, 6, 7           |           3 |
|     630 | 0, 1, 2           |           3 |
|     735 | 5, 6, 7, 8        |           4 |
|     840 | 0, 1, 2, 3        |           4 |

Total Hashing Comparisons

1 + 1 + 2 + 2 + 3 + 3 + 4 + 4 = 20

Average Hashing Comparisons

20 / 8 = 2.5

Therefore:

Average hashing comparisons = 2.5

2. Linear Search

In linear search, the elements are checked sequentially from the beginning of the list.

| Song ID | Position | Comparisons |
| ------: | -------: | ----------: |
|     105 |        1 |           1 |
|     210 |        2 |           2 |
|     315 |        3 |           3 |
|     420 |        4 |           4 |
|     525 |        5 |           5 |
|     630 |        6 |           6 |
|     735 |        7 |           7 |
|     840 |        8 |           8 |

Total Linear Search Comparisons

1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 = 36

Average Linear Search Comparisons

36 / 8 = 4.5

Therefore:

Average linear search comparisons = 4.5
## Performance Comparison

| Parameter                       |  Hashing |  Linear Search |
| ------------------------------- | -------: | -------------: |
| Total comparisons               |       20 |             36 |
| Average comparisons             |      2.5 |            4.5 |
| Best-case complexity            |     O(1) |           O(1) |
| Average-case complexity         |     O(1) |           O(n) |
| Worst-case complexity           |     O(n) |           O(n) |
| Collision handling              | Required | Not applicable |
| Suitable for frequent ID lookup |      Yes |  Less suitable |
## Time Complexity Analysis
Hashing
Best Case
When the required song ID is found at its initial hash position:
O(1)
Average Case
With a good hash function and a reasonable load factor:
O(1)
Worst Case
If many collisions occur and several positions must be checked:
O(n)
Linear Search
Best Case
The required element is the first element:
O(1)
Average Case
Approximately half of the elements may need to be checked:
O(n)
Worst Case
The element is at the last position or is not present:
O(n)
## Effect of Collisions on Search Performance
Collisions occur when two or more song IDs generate the same hash index.
In this implementation, the following IDs cause collisions:
105, 315, 525, 735
all initially map to index 5.
Similarly:
210, 420, 630, 840
all initially map to index 0.
Because of these collisions, linear probing is required. As a result, some searches require multiple comparisons.
For example, searching for 735 requires checking:
Index 5 → 105
Index 6 → 315
Index 7 → 525
Index 8 → 735
Therefore, 4 comparisons are required.
Thus, collisions reduce the efficiency of hashing. However, hashing still performs better than linear search for the given data.

## Result

The comparison shows:
Hashing:
Total comparisons = 20
Average comparisons = 2.5

Linear Search:
Total comparisons = 36
Average comparisons = 4.5

Hashing requires fewer comparisons than linear search for the given song IDs.

## Conclusion

Hashing is suitable for the music application because song IDs are unique numerical values and are frequently searched.
The Division Method provides direct access to the approximate location of a song ID, while linear probing is used to resolve collisions.
Although collisions occur because several song IDs produce the same hash value, hashing still requires fewer comparisons than linear search in this implementation.
Therefore, hashing is more efficient and suitable for song ID searching than linear search.
For better performance in larger applications, a suitable hash-table size and a good hash function should be selected to reduce collisions and maintain a lower load factor.
## Files in This Repository

DSA-Assignment-Q7-Hashing/

hashing.c       # C implementation

input.txt       # Input song IDs

output.txt      # Program output

README.md       # Project documentation

## Technologies Used
Programming Language: C
Data Structure: Hash Table
Hashing Technique: Division Method
Collision Resolution: Linear Probing
Searching Techniques: Hashing and Linear Search
