#pragma once
#include<iostream>
using namespace std;
struct Term
{
	int coef;
	int exp;
	Term *next;
	Term(int c, int e):coef(c), exp(e),next(nullptr)
	{

	}
	Term():coef(0),exp(-1),next(nullptr)
	{

	}
	Term(int c, int e, Term *n):coef(c), exp(c), next(n)
	{

	}
	void display(ostream & out,bool first)
	{
		if (coef > 0 && !first )
			out << '+';
		else if (coef == 0)
			return;
		out << coef;
		switch(exp)
		{
		case 0:break;
		case 1:out << 'x'; break;
		default:out << "x^" << exp; break;
		}	
	}

};
//class Poly;
//istream & operator >> (istream& ,Poly &);
//ostream & operator << (ostream &, const Poly &);
class Poly
{
private:
	bool is_sorted;
	Term *head;
	Term *tail;
	Poly( Term *h, Term *t):head(h),tail(t)
	{

	}
public:
	Poly()
	{
		is_sorted = false;
		head = tail = new Term();
	}
	//const Poly 

	////移动拷贝构造函数
	//Poly()
	//{

	//}


	Poly(const Poly & p)
	{
		is_sorted = p.is_sorted;
		cout << "copy constructor is called!" << endl;
		//Term *temp = p.head;		
		Term *cur_copy = p.head;
		head = new Term(cur_copy->coef, cur_copy->exp);
		tail = head;
		/*head->coef = cur_copy->coef;
		head->exp = cur_copy->exp;*/
		cur_copy = cur_copy->next;
		while(cur_copy)
		{
			Term *new_node = new Term(cur_copy->coef,cur_copy->exp);
			/*new_node->coef = cur_copy->coef;
			new_node->exp = cur_copy->exp;*/
			tail->next = new_node;
			tail = new_node;
			cur_copy = cur_copy->next;
		}
	}
	~Poly()
	{
		int count = 0;
		Term *temp ;
		while(head != nullptr)
		{
			temp = head->next;
			delete head;
			count++;
			head = temp;
		}
		printf("The total num of deleted term is %d\n", count);
	}
	//istream & operator >> (istream &, Poly &);
	//ostream & operator <<(ostream &, const Poly &);
	void append(int c, int e)
	{
		is_sorted = false;
		Term *new_node = new Term(c,e);
		tail->next = new_node;
		tail = new_node;
	}
	void display(ostream &out) const
	{
		bool is_first = true;
		Term * cur = head->next;
		while(cur != nullptr)
		{
			cur->display(out, is_first);
			if(is_first)
			{
				is_first = false;
			}
			cur = cur->next;
		}
	}


	Poly operator+( const Poly &rop) const
	{
		if( !is_sorted )
		{
			cout << "The poly must be sorted first." << endl;
			return Poly();
		}
		Term * result = new Term();
		Term *tail = result;
		//const Term *p = rop->head->next;
		const Term *p = rop.head->next;
		const Term *q = head->next;
		while( p != nullptr && q != nullptr)
		{
			Term *temp = new Term();
			if( p ->exp == q->exp )
			{
				temp->coef = p->coef + q->coef;
				temp->exp = p->exp;
				p = p->next;
				q = q->next;
			}
			else if( p->exp > q->exp)
			{
				temp->exp = p->exp;
				temp->coef = p->coef;
				p = p->next;
			}
			else
			{
				temp->exp = q->exp;
				temp->coef = q->coef;
				q = q->next;
			}
			tail->next = temp;
			tail = temp;
		}
		while( p != nullptr)
		{
			Term *node = new Term();
			node->coef = p->coef;
			node->exp = p->exp;
			tail->next = node;
			tail = node;
			p = p->next;
		}
		while( q != nullptr)
		{
			Term *node = new Term();
			node->coef = q->coef;
			node->exp = q->exp;
			tail->next = node;
			tail = node;
			q = q->next;
		}

		//Poly * poly_result = new Poly(result, tail);


		//调用一次拷贝构造函数
		//NVRO
		/*Poly temp_poly(result, tail);
		return temp_poly;*/


		//没有调用析构函数
		//一次拷贝构造函数也没调用
		//RVO
		return Poly(result, tail);
	}


	void sort()
	{
		if(is_sorted)
		{
			return;
		}
		is_sorted = true;

		if(head == tail)
		{
			return;
		}

		/*Term *pre_until = head;*/
		//Term *cur = head->next;

		Term *until = tail;
		while(head->next != until)
		{
			Term *flag = head->next;
			Term *pre_cur = head;		
			Term *cur = head->next;

			//保证cur之后一定至少有一个until
			//不会出现空指针的情况
			//while( cur != until  )
			//{				
			//	Term *cur_next = cur->next;
			//	if( cur->exp < cur_next->exp  )
			//	{
			//		//交换
			//		pre_cur->next = cur_next;
			//		cur->next = cur_next->next;
			//		cur_next->next = cur;	

			//		pre_cur = pre_cur->next;
			//		flag = cur_next;
			//	}
			//	else
			//	{
			//		//不交换
			//		pre_cur = cur;
			//		cur = cur_next;
			//	}
			//}


			//保证cur之后一定至少有一个until
			//不会出现空指针的情况
			while( cur != until  )
			{				
				Term *cur_next = cur->next;
				if( cur->exp < cur_next->exp  )
				{
					//交换
					if( cur_next == until)
					{
						until = cur;
					}
					pre_cur->next = cur_next;
					cur->next = cur_next->next;
					cur_next->next = cur;	

					pre_cur = pre_cur->next;
					flag = cur_next;
				}
				else
				{
					//不交换
					pre_cur = cur;
					cur = cur_next;
				}

			}
			until = flag;
			
		   
		}







	}
};
