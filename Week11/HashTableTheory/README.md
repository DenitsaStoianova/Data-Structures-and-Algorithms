# What is Hash Table? 
```
Hash table is a data structure that represents data in the form of key-value pairs. Each key is mapped to a value in 
the hash table. The keys are used for indexing the values/data. A similar approach is applied by an associative array.
```

# How do we represent data?
```
Data is represented in a key value pair. Each data is associated with a key. The key is an integer that point to the data.
Key | Data
```

# What is hash function?
```
Hashing is a technique to convert a range of key values into a range of indexes of an array. For example hash function 
converts a given big phone number to a small practical integer value. The mapped integer value is used as an index 
in the hash table. In simple terms, a hash function maps a big number or string to a small integer that can be used as 
the index in the hash table.
```

# What is a good hash function?
```
A good hash function has the following characteristics.
1.	It should not generate keys that are too large and the bucket space is small. Space is wasted.
2.	The keys generated should be neither very close nor too far in range.
3.	The collision must be minimized as much as possible.
```

# What is collision?
```
Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. 
The situation where a newly inserted key maps to an already occupied slot in hash table is called collision.
```

# Ways to handle collisions:

**1. Open Addressing** 

All elements are stored in the hash table itself. When searching for an element, we one by one examine table slots 
until the desired element is found or it is clear that the element is not in the table.

Open Addressing can be done in the following ways:

**Linear Probing:** 

In linear probing, collision is resolved by checking the next slot.
Challenges in Linear Probing:
1.	Primary Clustering - many consecutive elements form groups and it starts taking time to find a free slot or to search an element.  
2.	Secondary Clustering – two records do only have the same collision chain if their initial position is the same.

**Quadratic Probing**

**Double hashing**

**2. Linear Chaining** 

Each cell of hash table point to a linked list of records that have same hash function value.
Chaining is simple, but requires additional memory outside the table.
























