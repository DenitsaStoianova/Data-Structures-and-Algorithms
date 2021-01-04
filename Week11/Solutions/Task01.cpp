#pragma once

template <typename Key>
struct KeyHash // хеш функция - в случая е имплементирана като отделна структура (може да бъде представена с ламбда функция)
{
	int operator()(const Key& key) const
	{
		/*
		// вариант за изчисляване на хеш стойност, в случай че ключа е цяло число
		int number = key;
		int digitsSum = 0;
		while (number != 0)
		{
			digitsSum += number % 10;
			number /= 10;
		}
		return digitsSum % 6; // делене с остатък на капацитета на хеш таблиицата 
		*/
		
		// вариант за изчисляване на хеш стойност, в случай че ключа е символен низ
		int sum = 0;
		size_t keyLength = key.length();
		for (size_t i = 0; i < keyLength; i++)
		{
			sum += key[i];
		}
		return sum % 6;	// делене с остатък на капацитета на хеш таблиицата 
	}
};

template <typename Key, typename Value>
class HashTable
{
public:
	HashTable(const size_t& capacity);
	HashTable(const HashTable& other);
	HashTable& operator=(const HashTable& other);
	~HashTable();

	bool containsValue(const Key& key); //дали съществува дадена стойност в хеш таблицата

	Value getValue(const Key& key); //връщане на стойността на даден ключ

	// поставяне на нова стойност в таблицата
	// ако съществува елемент със същата хеш стойност и същия ключ като подадения, неговата стойност се променя (не се добавя отново)
	// ако съществува елемент със същата хеш стойност, но с различен ключ от подадения, неговата стойност се добавя като възел в свързания списък на съответния индекс в таблицата
	void put(const Key& key, Value value);

	void remove(const Key& key); //премахване на елемент по подаден ключ

	void print() const;
	const size_t& getCapacity() const;

private:
	template <typename Key, typename Value>
	struct EntryElement // Представяне на елемент от хеш таблицата
	{
		Key key;
		Value value;
		EntryElement* next;

		EntryElement(const Key& key, const Value& value, EntryElement* next = nullptr)
		{
			this->key = key;
			this->value = value;
			this->next = next;
		}
	};

private:
	EntryElement<Key, Value> **table; // масив от указатели към свързани списъци
	size_t capacity; // капацитет на хеш таблицата
	KeyHash<Key> hashFunction; // хеш функция

	void copy(const HashTable& other);
	void clear();
};

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(const size_t& capacity)
{
	this->capacity = capacity;
	this->table = new EntryElement<Key, Value>*[this->capacity];
	for (size_t i = 0; i < this->capacity; i++)
	{
		table[i] = nullptr;
	}
}

template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(const HashTable& other)
{
	this->copy(other);
}

template <typename Key, typename Value>
HashTable<Key, Value>& HashTable<Key, Value>::operator=(const HashTable& other)
{
	if (this != &other)
	{
		this->clear();
		this->copy(other);
	}
	return *this;
}

template <typename Key, typename Value>
HashTable<Key, Value>::~HashTable()
{
	this->clear();
}

template <typename Key, typename Value>
void HashTable<Key, Value>::copy(const HashTable& other)
{
	this->capacity = other.capacity;
	this->hashFunction = other.hashFunction;
	this->table = new EntryElement<Key, Value>*[this->capacity];

	EntryElement<Key, Value>* otherCurrent = nullptr;
	EntryElement<Key, Value>* copyFirst = nullptr;
	EntryElement<Key, Value>* copyCurrent = nullptr;

	for (size_t i = 0; i < this->capacity; i++)
	{
		otherCurrent = other.table[i];

		if (otherCurrent == nullptr)
		{
			table[i] = nullptr;
			continue;
		}

		copyFirst = new EntryElement<Key, Value>(otherCurrent->key, otherCurrent->value);
		copyCurrent = copyFirst;
		while (otherCurrent->next != nullptr)
		{
			copyCurrent->next = new EntryElement<Key, Value>(otherCurrent->next->key, otherCurrent->next->value);
			copyCurrent = copyCurrent->next;
			otherCurrent = otherCurrent->next;
		}
		this->table[i] = copyFirst;
	}
}

template <typename Key, typename Value>
void HashTable<Key, Value>::clear()
{
	EntryElement<Key, Value>* tableElement = nullptr;
	EntryElement<Key, Value>* prevHolder = nullptr;

	for (size_t i = 0; i < this->capacity; i++)
	{
		tableElement = table[i];
		while (tableElement != nullptr)
		{
			prevHolder = tableElement;
			tableElement = tableElement->next;
			delete prevHolder;
		}
		table[i] = nullptr;
	}

	delete[] table;
}


template <typename Key, typename Value>
bool HashTable<Key, Value>::containsValue(const Key& key)
{
	int tableIndex = hashFunction(key); // hash value
	EntryElement<Key, Value>* tableElement = table[tableIndex];

	while (tableElement != nullptr)
	{
		if (tableElement->key == key)
		{
			return true;
		}
		tableElement = tableElement->next;
	}

	return false;
}

template <typename Key, typename Value>
Value HashTable<Key, Value>::getValue(const Key& key)
{
	int tableIndex = hashFunction(key); // hash value
	EntryElement<Key, Value>* tableElement = table[tableIndex];
	Value value;

	while (tableElement != nullptr)
	{
		if (tableElement->key == key)
		{
			value = tableElement->value;
			break;
		}
		tableElement = tableElement->next;
	}

	return value;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::put(const Key& key, Value value)
{
	int tableIndex = hashFunction(key); // hash value
	EntryElement<Key, Value>* tableElement = table[tableIndex];
	EntryElement<Key, Value>* prevHolder = nullptr;

	while (tableElement != nullptr && tableElement->key != key)
	{
		prevHolder = tableElement;
		tableElement = tableElement->next;
	}

	if (tableElement == nullptr)
	{
		tableElement = new EntryElement<Key, Value>(key, value);

		if (prevHolder == nullptr)
		{
			table[tableIndex] = tableElement;
		}
		else
		{
			prevHolder->next = tableElement;
		}
	}
	else
	{
		tableElement->value = value; // update existing value
	}
}

template <typename Key, typename Value>
void HashTable<Key, Value>::remove(const Key& key)
{
	int tableIndex = hashFunction(key); // hash value
	EntryElement<Key, Value>* tableElement = table[tableIndex];
	EntryElement<Key, Value>* prevHolder = nullptr;

	while (tableElement != nullptr && tableElement->key != key)
	{
		prevHolder = tableElement;
		tableElement = tableElement->next;
	}

	if (tableElement == nullptr)
	{
		return;
	}
	else
	{
		if (prevHolder == nullptr)
		{
			table[tableIndex] = tableElement->next;
		}
		else
		{
			prevHolder->next = tableElement->next;
		}

		delete tableElement;
	}
}

template <typename Key, typename Value>
const size_t& HashTable<Key, Value>::getCapacity() const
{
	return this->capacity;
}

template <typename Key, typename Value>
void HashTable<Key, Value>::print() const
{
	EntryElement<Key, Value>* tableElement = nullptr;
	for (size_t i = 0; i < this->capacity; ++i)
	{
		tableElement = table[i];
		while (tableElement != nullptr)
		{
			std::cout << tableElement->key << ": " << tableElement->value << "\n";
			tableElement = tableElement->next;
		}
	}
}
