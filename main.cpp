#include "scoped_ptr.h"

int main()
{
	int *p = new int(10);
	int *q = new int(100);
	scoped_ptr<int>::scoped_ptr<int> pa(p);
	cout<<*pa<<endl;
	pa.reset(q);
	cout<<*pa<<endl;
	return 0;
}
