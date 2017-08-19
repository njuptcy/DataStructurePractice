template<typename T>
class Graph
{
public:
	virtual bool Insert(int u, int v, const T& w) = 0;
	virtual bool Exist(int u, int v) = 0;
	virtual bool Remove(int u, int v) = 0;
protected:
	int n, e;
};
