#include "hash_map.h"

hash_map::hash_map(size_t capacity)
{
    _capacity = capacity;
}

hash_map::hash_map(const hash_map &other)
{
		int size = other._size;
		hash_list* arr = new hash_list[size];
		for(int i = 0; i < size; i++){
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

}

size_t hash_map::get_capacity() const
{

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
