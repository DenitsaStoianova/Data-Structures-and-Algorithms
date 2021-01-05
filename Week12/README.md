# Седмица 12 - Хеш таблици (приложения)

**Задача 1:**

В текстов файл е записан имейл, в който имената на различните хора са отбелязани със символа @. Напишете програма, която при подаване на името на даден човек извежда колко пъти той е споменат в текста. При въвеждане на грешно име се извежда съответно съобщение на екрана.

```
Примерен файл:
Hi @John,
Nice to meet you! My name’s @Sara and I live in London with my mum @Anne, my little brother @Kevin and my father @Jo.
We live in a small house in Greenwich. I live near my school so I walk to school every day. My best friends are @Kim
and @Steph and we are in the same class. In the weekend I and @Kevin sometimes play in hockey matches. Often I, @Kim,
@Steph and @Kevin go roller-skating at the park.
Write soon and tell me all about yourself, your friends and your family.
Best wishes
@Sara  
Резултат:
Вход: Kevin                                                  Вход: Tom 
Изход: Kevin is mentioned 3 times at the text.               Изход: Tom is not mentioned at the text.
```

**Задача 2:**

Напишете програма, която намира вектора на дадена дума и неговата дължина. Вектор на дума представлява разбиването на думата на N последователни части от по 2 символа и броя на срещането на всяка такава част в думата. Дължината на вектора се намира по следната формула: sqrt(o1^2 + o2^2 + …. + oN^2), където о1…oN са броя на срещанията на всяка част в самата дума. 

```
Пример:
Вход: table
Резултат:
Word vector: { (ta, 1) (ab, 1) (bl, 1) (le, 1) }
Word vector length: 2 (Пресмята се по посочената формула: sqrt(1^2 + 1^2 + 1^2 + 1^2) = 2)
Вход: abracadabra
Резултат:
Word vector: { (br, 2) (ab, 2) (ac, 1) (ad, 1) (da, 1) (ca, 1) (ra,2) }
Word vector length: 4  (Пресмятяне: sqrt(2^2 + 2^2 + 1^2 + 1^2 + 1^2 + 1^2 + 2^2) = 4)
```

**Задача 3:**

Напишете програма, която симулира работата в магазин. Продуктите в магазина се пазят в склад (текстов файл, в който на отделни редове са записани продуктите и тяхното налично количество в магазина). Всеки клиент има списък с продукти, които желае да си закупи (За улеснение, даден клиент може да закупи само един брой от желания продукт). При пристигането си в магазина, той се нарежда на опашка, чакайки реда на обслужването си. Ако в магазина няма наличен продукт от списъка на даден потребител - се извежда  съответното съобщение на екрана. При успешно закупуване на продукт, неговото количество в склада намалява и се извежда подходящо съобщение с името на закупения продукт. След обслужването на всички клиенти изведете имената на тези клиенти, които са успели да закупят всички продукти от списъка си.

```
Примерни файлове:
Склад:
Apple - 5
Banana - 2
Pineapple - 4
Mango - 3
Клиенти:
John – Apple, Banana, Mango
Kim – Mango, Banana, Apple, Mango, Pineapple, Mango 
Sam – Banana, Pineapple
```
```
Вход:
Go shop:
John
Sam
Kim

Резултат:
Client John buy:
Apple
Banana
Mango
Client Sam buy:
Banana
Pineapple
Client Kim buy:
Mango
Product Banana is not available.
Apple
Mango
Pineapple
Product Mango is not available.
Clients bought all products:
Sam
John
```





