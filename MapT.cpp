

#include "MapT.h"
#include <unordered_map>
//using namespace std;

const int DEFAULT_BUCKETS = 10;
const double DEFAULT_LOAD = 1.0;


template<class K, class T>
MapT<K, T>::MapT() {

    // int arr*;
    // arr = new int[100];
    // Var name = new type[how many]

    numBuckets = DEFAULT_BUCKETS;
    numKeys = 0;
    maxLoad = DEFAULT_LOAD;

    buckets = new forward_list<pair<K, T>>[numBuckets];

}

template<class K, class T>
void MapT<K, T>::Add(K key, T value) {

    int bucket = GetHashIndex(key);


//    Remove(key);

    for (auto it = buckets[bucket].begin(); it != buckets[bucket].end(); ++it) {

        // "it" is an iterator object
        // "it" will behave like a pointer to the item

        // if the key for the current item is the same as the key we
        // are trying to add, replace the value of the item
        if (it -> first == key) {
            it -> second = value;
            return;
        }

    }


    pair<K, T> keyValuePair;
    keyValuePair.first = key;
    keyValuePair.second = value;

    buckets[bucket].push_front(keyValuePair);

    ++numKeys;


//    pair<int, int> myPair;
//    myPair.first = 5;
//    myPair.second = 10;



//    struct pair {
//        T first;
//        K second;
//    };

}

template<class K, class T>
bool MapT<K, T>::Contains(K key) {

    int bucket = GetHashIndex(key);

    for (auto it = buckets[bucket].begin(); it != buckets[bucket].end(); ++it) {

        if (it -> first == key) {
            return true;
        }
    }

    // did not find any item with key inside the bucket
    return false;

}

template<class K, class T>
int MapT<K, T>::GetHashIndex(const K &key) {
    unordered_map<K,T> mapper;
    typename unordered_map<K,T>::hasher hashFunction = mapper.hash_function();
    return static_cast<int>(hashFunction(key) % numBuckets);
}

template<class K, class T>
void MapT<K, T>::Remove(K key) {

}

template<class K, class T>
double MapT<K, T>::LoadFactor() {
    return 0;
}

template<class K, class T>
void MapT<K, T>::SetMaxLoad(double maxLoad) {

}

template<class K, class T>
void MapT<K, T>::Rehash(int numBuckets) {

}

template<class K, class T>
T MapT<K, T>::operator[](K key) {
    return nullptr;
}

template<class K, class T>
void MapT<K, T>::ResetIterator() {

}

template<class K, class T>
pair<K, T> MapT<K, T>::GetNextPair() {
    return pair<K, T>();
}



