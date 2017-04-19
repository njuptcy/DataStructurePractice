#pragma once
template<class T>
class I_seq_list
{
protected:
	int n;
public:
	virtual bool is_empty() const = 0;
	virtual bool is_full() const = 0;
	virtual bool at(int i, T &x) = 0;
	virtual int search(const T &x) const = 0;
	virtual bool insert(int i ,const T &x) = 0;
	virtual bool  remove(int i) = 0;
	virtual ~I_seq_list()
	{

	}
};