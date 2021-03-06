# Седмица 6 - Двоични дървета

[Основна теория за дървета](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/blob/main/Week06/BinaryTreeTheory/README.md)

[Имплементация на двоично дърво](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/tree/main/Week06/BinaryTreeImplementation)

[Основни видове обхождания](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/blob/main/Week06/TreeTraversals/TreeTraversals.cpp)

[Решения на задачите](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/tree/main/Week06/Solutions)

**Задача 1:**

Напишете функция, която за дадено двоично дърво намира:

1) Височината му - Височина на дърво наричаме дължината (в брой върхове) на най-дългия път от корена до кое да е листо на дървото

2) Нивото на което се намира даден възел от дървото

3) Сумата на всички възли

4) Броя на всички възли

5) Броя на всички вътрешни възли - Вътрешни възли наричаме възли, които не са листа


```
Примерно дърво:
                     8
                   /   \
                  3     2
                 / \   / \ 
                9   6 7   5 
                   / \
                  4   7
Резултат:
1. findHeight(root) -> 4
2. findLevel(root, root->left->right, 1) -> 3
3. findCount(root) -> 51
4. findCount(root) -> 9 
5. findInternalNodesCount(root) -> 4
```

**Задача 2:**

За дадено двоично дърво намерете:

1) Всички възможни пътища

2) Пътя от корена на дървото до даден възел

3) Сумата на най-дългия път 

```
Примерно дърво:
                     8
                   /   \
                  3     2
                 / \   / \ 
                9   6 1   5 
                   / \
                  4   7
                 /
                10
Резултат:
1. printAllPaths(root) -> 8 3 9
                          8 3 6 4 10
                          8 3 6 7
                          8 2 1
                          8 2 5
2. findPath(root, 4) -> 8 3 6 4
3. findLongestSum(root) -> 31
```

**Задача 3:**

Напишете функция, която проверява дали всеки възел от двоично дърво е равен на:

1) Cумата от лявото и дясното му дете

2) Cумата от лявото и дясното му поддърво

```
Примерно дърво 1:                                            
                    10                            
                   /   \
                  7     3
                 / \   /  
                6   1 3    
Резултат:
1. checkChildrenSum(root) -> true
2. checkSubtreeSum(root) -> false

Примерно дърво 2:                                            
                    30                            
                   /   \
                  10    5
                 / \     \
                4   6     5
Резултат:
1. checkChildrenSum(root) -> false
2. checkSubtreeSum(root) -> true

```

**Задача 4:**

За дадено двоично дърво проверете дали сумата на покритите и непокритите му възли е равна. (непокрити са възлите, намиращи се на лявата и дясната грaница на дървото, а покрити са оставащите възли)

```
Примерно дърво:
                     8
                   /   \
                  3     2
                 / \   / \ 
                9   6 1   5 
                   / \   /
                  4   7  9
сума на непокритите възли: 3 + 9 + 8 + 2 + 5 + 9 = 36        
сума на покритите възли: 6 + 1 + 4 + 7 = 18
=> 36 ?= 18
Резултат:
false
```
