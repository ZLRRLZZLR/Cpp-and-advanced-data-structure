#include"Stack."
#define _CRT_SECURE_NO_WARNINGS 1

////test.cpp
//#include<stdio.h>
//
//int main() {
//	printf("hello world\n");
//	return 0;
//}

//test.cpp
#include<iostream>
using namespace std;

//int main() {
//	//int i = 1;
//	//i << 10;
//
//	cout << "hello world\n" << endl;
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//namespace blog {
//	int rand = 10;
//}
//
//int a = 0;
//int main() {
//	printf("%p\n",rand);
//	printf("%d\n",blog::rand);
//
//	int a = 1;
//	printf("%d\n",a);
//
//	printf("%d\n",::a);
//
//	return 0;
//}

//#include<stdio.h>
//#include<stdlib.h>
//
//namespace blog
//{
//	int rand = 20;
//
//	int Add(int left, int right) {
//		return left + right;
//	}
//
//	struct Node {
//		struct Node* next;
//		int val;
//	};
//}
//
//int main() {
//	printf("%d\n",blog::Add(1,1));
//
//	struct blog::Node p1;
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

namespace blog {

	namespace b1 {
		int rand = 1;
		int Add(int left, int right) {
			return left + right;
		}
	}

	namespace b2 {
		int rand = 2;
		int Add(int left, int right) {
			return (left + right) * 10;
		}
	}
}

int main() {
	printf("%d\n",blog::b1::rand);
	printf("%d\n", blog::b2::rand);

}





