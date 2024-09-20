#include "hash_map.h"

hash_map::hash_map(size_t capacity)
{
    _capacity = capacity;
}

hash_map::hash_map(const hash_map &other)
{
		int cap = other._capacity;
		hash_list* arr = new hash_list[cap]; //Revert to size if dont work
		for(int i = 0; i < cap; i++){
			arr[i] = hash_list(other._head[i]);
		}
		
		_head = arr;
		_size = size;
		_capacity = other._capacity;
}

hash_map &hash_map::operator=(const hash_map &other)
{

}

void hash_map::insert(int key, float value)
{
	if(!get_value()){
		_size++;	
	}
	int key = (key < 0) ? key*-1 : key;
	int bin_num = key % _capacity;
	
	_head[bin_num].insert(key, value);
		
}

std::optional<float> hash_map::get_value(int key) const
{
    int hash_key = (key < 0 ? key * -1: key) % _capacity;
    return _head[hash_key].get_value();
}

bool hash_map::remove(int key)
{
    int hash_key = (key < 0 ? key * -1: key) % _capacity; //hashing function

    if(_head[hash_key].remove(key)) //only decrement size if something was removed
        size -= 1;
}

size_t hash_map::get_size() const
{
	return _size;
}

size_t hash_map::get_capacity() const
{
	return _capacity;	
}

void hash_map::get_all_keys(int *keys)
{

}

void hash_map::get_bucket_sizes(size_t *buckets)
{

}

hash_map::~hash_map()
{

}
