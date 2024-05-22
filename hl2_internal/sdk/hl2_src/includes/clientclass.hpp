#pragma once
#ifndef CLIENTCLASS_HPP
#define CLIENTCLASS_HPP

#include"../rect/dt_recv.h"

typedef void* (*CreateClientClassFn)(int, int);
typedef void* (*CreateEventFn)();

class ClientClass_t
{
public:
	CreateClientClassFn m_pClientClass;
	CreateEventFn m_pEventFn;
	ClientClass_t* m_pClass;
	RecvTable* m_pNext;
	char* m_szVar;
	int m_iClassId;
public:
	const char* GetName() const { return m_szVar; }
};

#endif