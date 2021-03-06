# Седмица 2 - Линеен двусвързан списък (обръщане, изтриване на елементи)

[Основни операции с двусвързан списък](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/blob/main/Week02/BasicOperations.cpp)

[Решения на задачите](https://github.com/DenitsaStoianova/Data-Structures-and-Algorithms/tree/main/Week02/Solutions)

Чрез директно използване на възлите на двусвързан списък да се решат следните задачи:

**Задача 1:**

Дефинирайте функцията void deleteAverage(Node* &first), която трие даден елемент от списъка, ако той е равен на средноаритметичното на първите два елемента, намиращи се от дясната му страна.

```
Пример:
Входен списък:
first: 5 <=> 3 <=> 7 <=> 3.5 -> 2 <=> 5 <=> 4.5 <=> 3 <=> 6 <=> 8 <=> 4
Резултат:
deleteAverage(first): 3 <=> 7 <=> 2 <=> 5 <=> 3 <=> 8 <=> 4
```

**Задача 2:**

Дефинирайте функцията void deleteSum(Node* &first), която намира разликата на най-големия и най-малкия елемент в списъка и ако в него съществува възел с такава стойност, изтрива всички негови срещания. В противен случай извежда съобщение, че не е намерен такъв елемент.

```
Пример:
Входен списък:
first: 3 <=> 5 <=> 2 <=> 1 <=> 4 <=> 6 <=> 5 <=> 5 <=> 1
Резултат:
deleteSum(first): 3 <=> 2 <=> 1 <=> 4 <=> 6 <=> 1
```

**Задача 3:**

Дефинирайте функцията void reverseFirstK(Node* &first, int k), която обръща първите K елемента на подадения списък.

```
Пример:
Входен списък:
first: 1 <=> 2 <=> 3 <=> 4 <=> 5 <=> 6 <=> 7 <=> 8
Резултат:
reverseFirstK(first, 4): 4 <=> 3 <=> 2 <=> 1 <=> 5 <=> 6 <=> 7 <=> 8 
```
**Задача 4:**

Дефинирайте функцията Node* mergeLists(Node* &evens,  Node* &odds), която получава два списъка, първият от които се състои само от четни числа, а вторият – от нечетни, проверява дали всеки от тях се състои от посочения вид елементи - при наличие на успех слива последователно елементите на подадените списъци в нов списък, редувайки четни с нечетни числа и го връща в обърнат ред. В противен случай извежда съобщение, че списъците не са коректни. 

```
Пример:
Входни списъци:
evens: 8 <=> 2 <=> 6 <=> 4
odds: 5 <=> 9 <=> 7 <=> 3 
Резултат:
mergeLists(evens, odds): 3 <=> 4 <=> 7 <=> 6 <=> 9 <=> 2 <=> 5 <=> 8
```
