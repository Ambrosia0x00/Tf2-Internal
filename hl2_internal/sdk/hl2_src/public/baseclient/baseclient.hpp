#pragma once
#ifndef BASECLIENT_HPP
#define BASECLIENT_HPP
#include"../../includes/clientclass.hpp"
#include"../../utils/vfunc/vfunc.hpp"
#include"../../includes/bitbuff.hpp"
class BaseClient_t
{
public:
	ClientClass_t* GetAllClasses()
	{
		return pFunc->CallVFunc<ClientClass_t*>(8, this);
	}
};
#endif