#pragma once

template<typename T>
class I_stack
{
public:
	virtual bool pop() = 0;
	virtual bool push(const T &x) = 0;
	virtual bool top(T &x) const = 0;
	virtual bool is_empty() const = 0;
	virtual bool is_full() const = 0;
};