#pragma once

#include<cstring>
const int SUCCESS = 0x1;
const int FAILURE = 0X2;
const int DUMPLICATE = 0X4;
const int NOTEXIST = 0x8;
const int OUTOFRANGE = 0X16;
char *get_result_str(int result)
{
	static char rs[128];
	memset(rs, 0, sizeof(rs));
	if (result & 0x1)
	{
		strcat(rs,"success ");
	}
	if (result & 0x2)
	{
		strcat(rs, "failure ");
	}
	if (result & 0x4)
	{
		strcat(rs,"dumplicate ");
	}
	if (result & 0x8)
	{
		strcat(rs, "noexisit ");
	}
	if (result & 0x16)
	{
		strcat(rs, "outofrange ");
	}
	return rs;
}
template<typename T>
class I_DynamicSet
{
public:
	virtual int search(const T& tar) = 0;
	virtual int insert(const T&tar) = 0;
	virtual int remove(const T&tar) = 0;
	virtual bool is_empty()=0;
	virtual bool is_full() = 0;
};
