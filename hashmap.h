#ifndef hashmap_H
#define hashmap_H
#include <iterator>

//implementation of a hashmap

template<typename TYPE>
class hashMap {
public:
	typedef unsigned size_type;
	//virtual = polymorphism, others can override
	virtual ~hashMap() {}
	//checks if hashMap is empty
	virtual bool isEmpty() const = 0;
	//finds size of hashMap
	virtual size_type size() const = 0;
	//returns iterator to beginning of hashMap
	virtual const TYPE& begin() const = 0;
	//returns iterator to end of hashMap
	virtual const TYPE& end() const = 0;
	//insert element 
	virtual void insert(const TYPE& val) = 0;
	//return size of individual buckets
	virtual size_type bucket_size() const = 0;
	//return number of buckets
	virtual size_type bucket_count() const = 0;
	//erase element from bucket & return following iterator
	virtual iterator erase() {}
	//clear entire table
	virtual void clear() {}
	//returns iterator to element from key
	virtual void find() {}


};

#endif //hashmap_H