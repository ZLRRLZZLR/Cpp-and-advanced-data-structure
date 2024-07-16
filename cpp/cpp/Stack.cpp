#include"Stack.h"

namespace STA
{
	void STInit(ST* ps, int n)
	{
		assert(ps);
		ps->a = (STDataType*)malloc(n * sizeof(STDataType));
		ps->top = 0;
		ps->capacity = n;
	}
	// ջ
	void STPush(ST* ps, STDataType x)
	{
		assert(ps);
		// ˣ 
		if (ps->top == ps->capacity)
		{
			printf("\n");
			int newcapacity = ps->capacity == 0 ? 4 : ps->capacity
				* 2;
			STDataType* tmp = (STDataType*)realloc(ps->a,
				newcapacity * sizeof(STDataType));
			if (tmp == NULL)
			{
				perror("realloc fail");
				return;
			}

			ps->a = tmp;
			ps->capacity = newcapacity;
		}

		ps->a[ps->top] = x;
		ps->top++;
	}
}