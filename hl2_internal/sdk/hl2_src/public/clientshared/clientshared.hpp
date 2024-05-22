#pragma once
#ifndef CLIENTSHARED_HPP
#define CLIENTSHARED_HPP

class ClientDllSharedAppSystem_t
{
public:
	virtual int Count() = 0;
	virtual char const* GetDllName(int idx) = 0;
	virtual char const* GetInterfaceName(int idx) = 0;
};

#endif