  # Sorting Algorithms - Complexity

|  Algorithm	      |  Best          |  Worst       |  Average     |  Space/Worst  |
|  ---------------  |  ------------  |  ----------  |  ----------  |  -----------  | 
|  Bubble Sort      |  O(n)          |  O(n^2)      |  O(n^2)      |  O(1)         |      
|  Selection Sort   |  O(n^2)        |  O(n^2)      |  O(n^2)      |  O(1)         |         
|  Insertion Sort   |  O(n)          |  O(n^2)      |  O(n^2)      |  O(1)         |           
|  Quicksort        |  O(n*logn)     |  O(n^2)      |  O(n*logn)   |  O(logn)      |               
|  Mergesort        |  O(n*logn)     |  O(n*logn)   |  O(n*logn)   |  O(n)         |         


# How to choose best sorting algorithm?

    **Does the data fit in RAM?** 

          No  -> Mergesort
   
          Yes -> **Are swaps expensive?** 
   
                      Yes -> Seection Sort
              
                      No -> **Is the data mostly sorted?** 
                          
                                   Yes -> Insertion Sort
                          
                                   No -> **Can we use extra space?**
                                      
                                               No -> Quicksort
                                       
                                               Yes -> **Does it need to be stable?** 
                                                   
                                                            No -> Quicksort
                                                    
                                                            Yes -> Mergesort  
                     
                     
                     
