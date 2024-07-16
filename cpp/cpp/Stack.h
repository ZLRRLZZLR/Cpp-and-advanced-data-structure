#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

namespace STA
{
	typedef int STDataType;
	typedef struct stack
	{
		STDataType* a;
		int top;
		int capacity;
	}ST;

	void STInit(ST* ps,int n = 4);
	void STDestroy(ST* ps);
	void STPush(ST* ps,STDataType x);
	void STPop(ST* ps);
	STDataType StTop(ST* ps);
	int STSize(ST* ps);
	int STsize(ST* ps);
	bool STEmpty(ST* ps);
}