



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