#include<assert.h>
#include<list>
#include<string>
#include<unordered_map>

using namespace std;


class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {



	}

	void put(int key,int value) {


	}


private:
	list<pair<int, int>> _list;
	size_t _capacity;
	unordered_map<int, list<int, int>::iterator> _hashmap;
};





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



//单例模式
// 将默认构造设置为私有，这样外部无法直接new
// 饿汉实现
//template<typename T>
//class Singleton {
//public:
//	static T* GetInstance() {
//		return &data;
//	}
//	~Singleton();
//
//private:
//	Singleton();
//	static T data;
//};
//
//template <typename T>
//class Singleton {
//懒汉实现
//private:
//	static T* inst;
//	Singleton();
//
//public:
//	static T* GetInstance() {
//		if (inst == nullptr) {
//			inst = new T();
//		}
//		return inst;
//	}
//
//	~Singleton();
//};