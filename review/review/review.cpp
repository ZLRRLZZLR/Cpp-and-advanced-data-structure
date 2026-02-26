#include<assert.h>
#include<list>
#include<string>
#include<unordered_map>
#include<mutex>

using namespace std;

////手撕strcmp
//int strcmp(char* str1,char* str2) {
//	while (*str1 == *str2 && *str1 != '\0') {
//		++str1;
//		++str2;
//	}
//	return *str1 - *str2;
//}
////手撕strcat
//char* mystrcat(char* dst,char*src) {
//	char* res = dst;
//	while (*dst != '\0') ++dst;
//	while (*src != '\0') {
//		*dst = *src;
//		src++;
//		dst++;
//	}
//	*dst = '\0';
//	return res;
//}

//手撕strcpy
//char* mystrcpy(char* dest, const char* src) {
//	assert(dest);
//	assert(src);
//	char* tmp = dest;
//	while (*src != '\0') {
//		*dest = *src;
//		dest++;
//		src++;
//	}
//	return tmp;
//}
////strstr手撕
//char* mystrstr(const char* str1,const char* str2) 
//{
//	assert(str1);
//	assert(str2);
//	if (*str2)
//		return (char*)str1;
//	char* cp = (char*)str1;
//
//	while (*cp) {
//		char* s1 = cp;
//		char* s2 = (char*)str2;
//		while (*s1 && *s2 && *s1 == *s2) {
//			s1++;
//			s2++;
//			if (!*s2) return cp;
//		}
//		cp++;
//	}
//	return NULL;
//}
////memmove手撕
//void* mymemmove(void* destination, const void* source, size_t num) {
//	void* res = destination;
//	assert(destination);
//	assert(source);
//	if ((char*)destination <= (char*)source || (char*)source + num <= destination) {
//		*(char*)destination = *(char*)source;
//		source = (char*)source + 1;
//		destination = (char*)destination + 1;
//	}
//	else
//	{
//		source = (char*)source + num - 1;
//		destination = (char*)destination + num - 1;
//		while (num--) {
//			*(char*)destination = *(char*)source;
//			source = (char*)source - 1;
//			destination = (char*)destination - 1;
//		}
//	}
//	return res;
//}

////memcpy手撕
//void* mymemcpy(void* destination, const void* source, size_t num) {
//	void* res = destination;
//	assert(destination);
//	assert(source);
//	while (num--) {
//		*(char*)destination = *(char*)source;
//		destination = (char*)destination + 1;
//		source = (char*)source + 1;
//	}
//	return res;
//}


////枚举
//enum Sex
//{
//	RED = 1,
//	GREEN = 2,
//	BLUE = 4
//};
//
////联合体
//union un {
//	int a;
//};

//判断当前及其的字节序是什么(判断大小端)

//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};

//int main() {
//	union {
//		int i;
//		char c;
//	}un;
//
//	un.i = 1;
//	return un.c;
//}

//int main()
//{
//	int a = 1;
//	char* p = (char*)&a;
//	if (*p == 1) {
//		printf("小端\n");
//	}
//	else {
//		printf("大端\n");
//	}
//
//}

//class lazy
//{
//public:
//	static lazy* getinstance() {
//		if (_instance == nullptr) {
//			_mtx.lock();
//			if (_instance == nullptr) {
//				_instance = new lazy();
//			}
//			_mtx.unlock();
//		}
//		return _instance;
//	}
//private:
//	lazy(){}
//	lazy(const lazy&) = delete;
//	lazy& operator=(const lazy&) = delete;
//
//private:
//	static mutex _mtx;
//	static lazy* _instance;
//};
//
//lazy* lazy::_instance = nullptr;
//mutex lazy::_mtx;
//
//
//class hunger
//{
//public:
//	static hunger* getinstance() {
//		return &_instance;
//	}
//
//private:
//	hunger(){}
//	hunger(const hunger&) = delete;
//	hunger& operator=(const hunger&) = delete;
//
//private:
//	static hunger _instance;
//};
//
//hunger hunger::_instance;


//
//class LRUCache {
//public:
//	LRUCache(int capacity) {
//		_capacity = capacity;
//	}
//
//	int get(int key) {
//		auto hashit = _hashmap.find(key);
//		if (hashit != _hashmap.end()) {
//			auto listit = hashit->second;
//			pair<int, int> value = *listit;
//			_list.erase(listit);
//			_list.push_front(value);
//			_hashmap[key] = _list.begin();
//			return value.first;
//		}
//		else {
//			return -1;
//		}
//
//	}
//
//	void put(int key,int value) {
//		auto hashit = _hashmap.find(key);
//		if (hashit != _hashmap.end()) {
//			auto listit = hashit->second;
//			pair<int, int> value = *listit;
//			_list.erase(listit);
//			_list.push_front(value);
//			_hashmap[key] = _list.begin();
//
//		}
//		else {
//			pair<int, int> listit = _list.back();
//			if (_hashmap.size() >= _capacity)
//			{
//				_list.pop_back();
//				_hashmap.erase(listit.first);
//			}
//			_list.push_front(make_pair(key, value));
//			_hashmap[key] = _list.begin();
//		}
//
//	}
//
//
//private:
//	list<pair<int, int>> _list;
//	size_t _capacity;
//	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;
//};





//手撕vector
////模拟实现vector类，并完成测试
//namespace bit
//
//{
//
//    template<class T>
//
//    class vector
//
//    {
//
//    public:
//
//        // Vector的迭代器是一个原生指针
//
//        typedef T* iterator;
//        typedef const T* const_iterator;
//
//          iterator begin() {
//              return _start;
//        }
//
//          iterator end() {
//              return _finish;
//            }
//
//          const_iterator cbegin() const {
//              return _start;
//            }
//
//          const_iterator cend() const {
//              return _finish;
//            }
//
//
//            // construct and destroy
//            vector()
//                :_start(nullptr),_finish(nullptr),_endOfStorage(nullptr)
//            {}
//
//            vector(int n, const T& value = T())
//                :_start(nullptr),_endOfStorage(nullptr),_finish(nullptr)
//            {
//                resize(n, value);
//            }
//
//            template<class InputIterator>
//            vector(InputIterator first, InputIterator last) {
//                reserver(last - first);
//
//                while (first != last) {
//                    push_back(*first);
//                    first++;
//                }
//            }
//
//                vector(const vector<T>& v) {
//                    reserve(v.size();
//                    iterator begin = v.begin();
//                    iterator end = v.end()
//                        while (begin!=end) {
//                            push_back(*begin);
//                            begin++;
//                    }
//
//                    _finish = _start + v.size();
//
//                    _endOfStorage = _start + v.capacity();
//
//                }
//
//                vector<T>& operator= (vector<T> v) {
//                    swap(v);
//                    return *this;
//            }
//
//                ~vector() {
//                delete _start;
//                _start = nullptr;
//                _finish = nullptr;
//                _endOfStorage = nullptr;
//            }
//
//                // capacity
//
//                size_t size() const {
//                return _finish - _start;
//            }
//
//            size_t capacity() const {
//                return _endOfStorage - _start;
//            }
//
//            void reserve(size_t n) {
//                if (n > capacity()) {
//                    int OldSize = size();
//
//                    T* tmp = new T[n];
//                    for (int i = 0; i < OldSize; i++) {
//                        tmp[i] = _start[i];
//                    }
//
//                    _start = tmp;
//                    _finish = _start + OldSize;
//                    _endOfStorage = _start + n;
//                }
//        }
//
//            void resize(size_t n, const T& value = T()) {
//                if (n <= capacity()) {
//                    _finish = _start + n;
//                    return;
//                }
//                else {
//                    reserver(n);
//                    iterator it = _finish;
//                    _finish = _start + n;
//
//                    while (it != _finish) {
//                        *it = value;
//                        ++it;
//                    }
//                }
//            }
//
//                ///////////////access///////////////////////////////
//
//            T& operator[](size_t pos) {
//                return _start[pos];
//            }
//
//
//            const T& operator[](size_t pos)const {
//                return _start[pos];
//            }
//
//            ///////////////modify/////////////////////////////
//
//            void push_back(const T& x) {
//                insert(end(),x);
//            }
//
//            void pop_back() {
//                erase(--end());
//            }
//
//            void swap(vector<T>& v) {
//                swap(_start, v._start);
//                swap(_finish, v._finish);
//                swap(_endOfStorage, v._endOfStorage);
//            }
//
//            iterator insert(iterator pos, const T& x) {
//                assert(pos <= _finish);
//
//                if (_finish == _endOfStorage) {
//                    int size = size();
//                    int newcapacity = 0;
//                    int newcapacity = capacity() == 0 ? 4 : capacity() * 2;
//                    reserve(newcapacity);
//                    pos = _start + size;
//                }
//
//                iterator end = _finish - 1;
//                while (end >= pos) {
//                    *(end + 1) = *end;
//                    end--;
//                }
//                *pos = x;
//                _finish++;
//                return pos
//            }
//
//            iterator erase(Iterator pos) {
//                assert(pos <= finish);
//                iterator begin = pos + 1;
//
//                while (begin < filish) {
//                    *begin - 1 = *(begin);
//                    ++begin;
//                }
//
//                _finish--;
//
//                return pos
//            }
//
//
//    private:
//
//        iterator _start; // 指向数据块的开始
//
//        iterator _finish; // 指向有效数据的尾
//
//        iterator _endOfStorage; // 指向存储容量的尾
//
//    };
//
//}


