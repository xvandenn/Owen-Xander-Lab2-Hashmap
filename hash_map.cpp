#include "hash_map.h"

hash_map::hash_map(size_t capacity)
{
    _capacity = capacity;
    _head = new hash_list[capacity];
    for(int i = 0; i < (int)_capacity; i++)
        _head[i] = hash_list();
    _size = 0;
}

hash_map::hash_map(const hash_map &other)
{
		this->~hash_map();
		_size = other._size;
		_capacity = other._capacity;
		hash_list* arr = new hash_list[other._capacity]; //Revert to size if dont work
		for(int i = 0; i < (int)other._capacity; i++){
			arr[i] = hash_list(other._head[i]);
		}
		
		_head = arr;
}

hash_map &hash_map::operator=(const hash_map &other)
{
    if(_head == other._head)
        return *this;
    this->~hash_map();
	_capacity = other._capacity;
    _head = new hash_list[_capacity];
    for(int i = 0; i < (int)_capacity; i++)
		_head[i] = other._head[i];
	_size = other._size;
    return *this;

}

void hash_map::insert(int key, float value)
{
	if(!get_value(key)){
		_size++;	
	}
	key = (key < 0) ? key*-1 : key;
	int bin_num = key % _capacity;
	
	_head[bin_num].insert(key, value);
		
}

std::optional<float> hash_map::get_value(int key) const
{
    int hash_key = (key < 0 ? key * -1: key) % _capacity;
    return _head[hash_key].get_value(key);
}

bool hash_map::remove(int key)
{
    int hash_key = (key < 0 ? key * -1: key) % _capacity; //hashing function

    if(_head[hash_key].remove(key))
    { //only decrement size if something was removed
        _size -= 1;
        return true;
    }
    return false;
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

		int idx = 0;
		for(int i = 0; i < (int)_capacity; i++){
		_head[i].reset_iter();
		while(!_head[i].iter_at_end()){
			keys[idx] = *(_head[i].get_iter_value().value().first);
			idx++;
			_head[i].increment_iter();
		}
	}

}

void hash_map::get_bucket_sizes(size_t *buckets)
{
    for(int i = 0; i < (int)_capacity; i++)
        buckets[i] = _head[i].get_size();
}

hash_map::~hash_map()
{
	for(int i =0; i < (int)_capacity; i++){
		_head[i].~hash_list();
	}
	delete _head;
}
