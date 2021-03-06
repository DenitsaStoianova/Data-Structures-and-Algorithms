# Седмица 9 - Различни видове дървета (Дървета с произволен брой наследници)

[Основна теория за различните видове двоични дървета](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/blob/main/Week09/TreesTheory/README.md)

[Решения на задачите](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/tree/main/Week09/Solutions)

**Задача 1:**

Напишете функция, която проверява дали дадено двоично дърво е:

1. Full Binary Tree

2. Perfect Binary Tree

3. Complete Binary Tree

```
Примерно дърво:
                     6 
                   /   \
                  4     3
                 / \      
                9   5 
Резултат:
1. isFull(root) -> true
2. isPerfect(root) -> false
3. isComplete(root) -> true
```

# Дървета с произволен брой наследници

[Имплементация с вектор](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/tree/main/Week09/TreeContainerImplementation)

[Импрементация "най-ляв син - десен брат"](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/tree/main/Week09/TreeSiblingsImplementation)

**Задача 2:**

Напишете функция, която:

1. Конструира дърво с много наследници от символен низ, който има следния вид (корен[(поддърво 1)...(поддърво n)]).

2. Превръща дърво с много наследници в символен низ, имащ гореспоменатия вид.

```
Пример:
Символен низ: (A[(C[(H)(F)])(B)(P[(K)(M)(V)])])
Построено дърво:
                      A
                   /  |  \
                  C   B   P 
                 / \    / | \ 
                H   F  K  M  V
```

**Задача 3:**

Напишете функция, която за дадено дърво с произволен брой наследници намира броя възли, по-големи от подадена стойност.

```
Примерно дърво:
                     10
                   /  |  \
                  4   3   5 
                 / \    / | \ 
                2   6  9  2  7
                
Брой възли, които имат стойности по-големи от 6: 3                 
```

**Задача 4:**

В дърво с произволен брой наследници намерете възела, който събран с преките си наследници има най-голяма сума.

```
Примерно дърво:
                      1
                   /  |  \
                  4   2   5 
                 / \    / | \ 
                9   6  3  4  6
                
Възел с най-голяма сума: 5           
```
