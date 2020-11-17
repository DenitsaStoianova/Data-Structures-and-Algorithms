# Седмица 7 - Двоични наредени дървета

Имплемептация

**Задача 1:**

Напишете функция, която изтрива елемент от двоично наредено дърво по подадена стойност.

```
Примерно дърво:
                     10
                   /   \
                  4     15
                 / \   / \ 
                2   7 13   18 
                   / \
                  6   9
Резултат след изтриването на елемента със стойност 4:
                     10
                   /   \
                  7     15
                 / \   / \ 
                2   9 13   18 
                   / 
                  6                     
```

**Задача 2:**

Намерете най-ниският общ предшественик на два възела в двоично наредено дърво.

```
Примерно дърво:
                     10
                   /   \
                  4     15
                 / \   / \ 
                2   7 13   18 
                   / \
                  6   9
Най-нисък общ предшественик на 6 и 2: 4
```

**Задача 3:**

Към всеки възел на двоично наредено дърво добавете сумата на всички по-големи от него възли. Полученото дърво все още ли е двоично наредено?


```
Примерно дърво:
                     10
                   /   \
                  4     15
                 / \   / \ 
                2   7 13   18 
                   / \
                  6   9
Резултат:
                     56
                   /    \
                  26     46
                 / \    /  \ 
                2   16 13  18 
                   / \
                  6   9
```

**Задача 4:**

Напишете функция, каято преръща двоично дърво в двоично наредено.

```
Примерно дърво:
                     8
                   /   \
                  3     2
                 / \   / \ 
                9   6 9   5 
                   / \
                  4   7
Резултат:
```

**Задача 5:**

Напишете програма, която прочита двоично дърво от файл, представено по следния начин, проверява дали то е двоично дърво за търсене и след това записва дървото заедно с получения резултат в отделен файл.
Дървото е представено във файла по следния начин (5 (3 (1 () ()) ()) (7 (6 () ()) (9 () (10 () ()))))



