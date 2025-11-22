//两个线程交替打印奇数偶数
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

int main()
{
	std::mutex mtx;
	condition_variable c;
	int n = 100;
	bool flag = true;

	thread t1([&]() {
		int i = 0;
		while (i < n) {
			unique_lock<mutex> lock(mtx);
			//flag == flase t1一直阻塞
			//flag == true t1不会阻塞
			while (!flag) {
				c.wait(lock);
			}

			cout << i << endl;
			flag = false;
			i += 2;//偶数

			c.notify_one();
		}
		});

	thread t2([&]() {
		int j = 1;
		while (j < n) {
			unique_lock<mutex> lock(mtx);
			while (flag) {
				c.wait(lock);
			}

			cout << j << endl;
			flag = true;
			j += 2;//奇数

			c.notify_one();
		}
		});

	t1.join();
	t2.join();


	return 0;
}
