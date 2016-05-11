#ifndef __SCOPED_H__
#define __SCOPED_H__
#include <iostream>
using namespace std;

template<class T>
class scoped_ptr
{
	private:
		T* px;
		typedef scoped_ptr<T> this_type;
		scoped_ptr(scoped_ptr const& );
		scoped_ptr& operator=(scoped_ptr const&);
		bool operator==(scoped_ptr const&) const;
		bool operator!=(scoped_ptr const&) const;
	public:
	scoped_ptr(T* p = 0)
		:px(p)
	{}
//	scoped_ptr(auto_ptr<T> p):px(p.release())
//	{}
	~scoped_ptr()
	{
		delete px;
	}
	T& operator*()
	{
		return *get();
	}
	T& operator->()
	{
		return px;
	}
	T* get()
	{
		return px;
	}
	void reset(T* p = 0)
	{
//		if(px != p)
//			delete px;
//		px = p;
		this_type(p).swap(*this);
	}
	void swap(scoped_ptr<T>& b)
	{
		T* tmp = b.px;
		b.px = px;
		px = tmp;
	}
};

#endif
