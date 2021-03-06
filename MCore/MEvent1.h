/*
*	Event1 
*		1 parameter event & listener
*
*	Author: SiZhong.Wang, M-001
*
*	CopyRight: SilverEyes Information CO. LTD.
*/
#pragma once

#include "MEvent.h"

namespace Rad {

	template<class P1>
	class _tListener1 : public _tListener
	{
	public:
		virtual ~_tListener1() {}

		virtual void OnCall(P1 p1) = 0;
	};

	template<class P1>
	class tEvent1 : public _tEvent
	{
	public:
		typedef _tListener1<P1> listener_t;

	public:
		void operator +=(listener_t * _listener)
		{
			Attach(_listener);
		}

		void operator -=(listener_t * _listener)
		{
			Detach(_listener);
		}

		void operator ()(P1 p1)
		{
			_tListener * node = mHead;
			_tListener * next = NULL;

			while (node != NULL)
			{
				next = node->_Next;

				static_cast<listener_t *>(node)->OnCall(p1);

				node = next;
			}
		}
	};

	template <class T, class P1>
	class cListener1 : public _tListener1<P1>
	{
		typedef void (T::*Function)(P1 p1);

		T * _This;
		Function _Fn;

	public:
		cListener1() : _This(NULL), _Fn(NULL) {}
		cListener1(T * _listener, Function _func) : _This(_listener), _Fn(_func) {}
		virtual ~cListener1() {}

		virtual void OnCall(P1 p1)
		{
			d_assert (_This != NULL && _Fn != NULL);

			(_This->*_Fn)(p1);
		}

		cListener1 * operator()(T * _listener, Function _func)
		{
			_This = _listener;
			_Fn = _func;

			return this;
		}
	};

	template<class P1>
	class ncListener1 : public _tListener1<P1>
	{
		typedef void (*Function)(P1 _p1);

		Function _Fn;

	public:
		ncListener1(Function _func) : _Fn(_func) {}
		virtual ~ncListener1() {}

		virtual void OnCall(P1 p1)
		{
			d_assert (_Fn != NULL);

			_Fn(p1);
		}
	};

}
