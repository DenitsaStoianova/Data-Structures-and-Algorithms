 # Sorting Algorithms - Complexity

|  Algorithm	      |  Best          |  Worst       |  Average     |  Space/Worst  |
|  ---------------  |  ------------  |  ----------  |  ----------  |  -----------  | 
|  Bubble Sort      |  O(n)          |  O(n^2)      |  O(n^2)      |  O(1)         |      
|  Selection Sort   |  O(n^2)        |  O(n^2)      |  O(n^2)      |  O(1)         |         
|  Insertion Sort   |  O(n)          |  O(n^2)      |  O(n^2)      |  O(1)         |           
|  Quicksort        |  O(n*logn)     |  O(n^2)      |  O(n*logn)   |  O(logn)      |               
|  Mergesort        |  O(n*logn)     |  O(n*logn)   |  O(n*logn)   |  O(n)         |         


# How to choose best sorting algorithm?

    Does the data fit in RAM? 
    ------------------------- 
          No  -> Mergesort
   
          Yes -> Are swaps expensive? 
                 ---------------------
                      Yes -> Seection Sort
              
                      No  -> Is the data mostly sorted? 
                             --------------------------
                                   Yes -> Insertion Sort
                          
                                   No  -> Can we use extra space?
                                          -----------------------
                                               No  -> Quicksort
                                       
                                               Yes -> Does it need to be stable? 
                                                      --------------------------
                                                            No  -> Quicksort
                                                    
                                                            Yes -> Mergesort  
                     
                     
# When to use each sorting algorithm?

**Bubble Sort**

```
- It works well with large lists where the items are almost sorted because it takes only one iteration to detect whether the list is sorted or not. 

- If the list is unsorted to a large extend then this algorithm holds good for small datasets or lists.

- This algorithm is fastest on an extremely small or nearly sorted set of data.
```

**Selection Sort**

```
- When the list is small. As the time complexity of selection sort is O(n^s) which makes it inefficient for a large list.

- When memory space is limited because it makes the minimum possible number of swaps during sorting.
```

**Insertion Sort**

```
- If the data is nearly sorted or when the list is small as it has a complexity of O(n^2) and if the list is sorted a minimum number of elements will slide over to insert the element at it’s correct location.

- This algorithm is stable and it has fast running case when the list is nearly sorted.

- The usage of memory is a constraint as it has space complexity of O(1).
```

**Quicksort**

```
- Quick sort is fastest, but it is not always O(n*logn), as there are worst cases where it becomes O(n^2).

- Quicksort is probably more effective for datasets that fit in memory. For larger data sets it proves to be inefficient so algorithms like merge sort are preferred in that case.

- Quick Sort in is an in-place sort (i.e. it doesn’t require any extra storage) so it is appropriate to use it for arrays.
```

**Mergesort**

```
- When the data structure doesn’t support random access since it works with pure sequential access that is forward iterators, rather than random access iterators.

- It is widely used for external sorting, where random access can be very, very expensive compared to sequential access.

- Merge sort is fast in the case of a linked list.

- It is used in the case of a linked list as in linked list for accessing any data at some index we need to traverse from the head to that index and merge sort accesses data sequentially and the need of random access is low.

- The main advantage of the merge sort is its stability, the elements compared equally retain their original order.
```
