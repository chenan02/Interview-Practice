#ifndef hashmap_vector_H
#define hashmap_vector_H

#include <vector>
#include "hashmap.h"

//An implementation of an unordered_map with a vector as the underlying data structure
template<typename TYPE, typename HASH>
class hashMap_vector : public hashMap {
	vector<TYPE> data;
public:
	typedef unsigned size_type;
	template <typename iterator>
	//constructor
	hashMap_vector();
	hashMap_vector(initializer_list<TYPE> il);

	virtual bool isEmpty() const {
		return data.empty();
	}
	virtual size_type size() const {
		return data.size();
	}
	virtual iterator begin() const;
	virtual iterator end() const;
	virtual void insert();
	virtual size_type bucket_size() const;
	virtual size_type bucket_count() const;
	virtual iterator erase();
	virtual void clear();
	virtual iterator find();
};

template<typename TYPE, typename HASH>
hashMap_vector<TYPE, HASH>::hashMap_vector() {

}

template<typename TYPE, type HASH> 
hashMap_vector<TYPE, HASH>::hashMap_vector(initializer_list<TYPE> il) {

}

template<typename iterator>
iterator hashMap_vector<TYPE, HASH>::begin() {

}

template<typename iterator>
iterator hashMap_vector<TYPE, HASH>::end() {

}

template

template<