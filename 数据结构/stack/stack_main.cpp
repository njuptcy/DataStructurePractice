#include"../which_to_run.h"

#ifdef _STACK_MAIN_
#include"I_stack.h"
#include"seq_stack.h"

#include<iostream>
using namespace std;
int main()
{
	const int max_size = 4;
	I_stack<int>  * stack = new Seq_stack<int>(max_size);
	for(int i = 0; i < 5; i++)
	{
		if (!(stack->push(i)))
			printf("when push %d, fail.\n", i);

	}
	for(int i = 0; i < 5; i++)
	{
		int x;
		if (stack->top(x))
			printf("the num on top is:%d.\n", x);
		else
			printf("nothing more!\n");
		stack->pop();
	}
	getchar();

}
#endif