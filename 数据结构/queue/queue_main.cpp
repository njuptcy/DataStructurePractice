#include"../which_to_run.h"
#ifdef _QUEUE_MAIN_

#include"i_queue.h"
#include"seq_queue.h"
#include"single_queue.h"
#include"single_cycle_queue.h"
int main()
{
	const int max_size = 5;
	//I_queue<int> * queue = new Seq_queue<int>(max_size);
	//I_queue<int> * queue = new Single_queue<int>();
	I_queue<int> * queue = new Single_cycle_queue<int>(3);
	for(int i = 0; i < 5; i++)
	{
		queue->en_queue(i);
	}
	for(int i = 0; i < 5; i++)
	{
		int x = 0;
		if(queue->front(x))
		{
			printf("queue front is: %d \n",x);
		}
		else
		{
			printf("nothing front\n");
		}
		queue->de_queue();
	}
	delete queue;
	getchar();
}
#endif