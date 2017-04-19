#pragma once
template<typename T>
class I_queue
{
public:
	virtual bool en_queue(const T &x) = 0;
	virtual bool de_queue() = 0;
	virtual bool front(T &x) const = 0;
	virtual bool is_empty() const = 0;
	virtual bool is_full() const = 0;
	virtual ~I_queue()
	{
	}
};