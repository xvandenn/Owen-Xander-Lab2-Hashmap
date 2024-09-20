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

}

std::optional<float> hash_map::get_value(int key) const
{


}

bool hash_map::remove(int key)
{

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
