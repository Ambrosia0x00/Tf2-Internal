#pragma once
#ifndef ENTITYLIST_HPP
#define ENTITYLIST_HPP

#include"../entity/entity.hpp"
#include"../../utils/vfunc/vfunc.hpp"

class EntityList_t
{
public:
	BaseEntity_t* GetClientEntity(int idx)
	{
		return pFunc->CallVFunc<BaseEntity_t*>(3, this, idx);
	}
	BaseEntity_t* GetClientEntityFromHandle(int idx)
	{
		return pFunc->CallVFunc<BaseEntity_t*>(4, this, idx);
	}
	int GetHighestEntityIndex()
	{
		return pFunc->CallVFunc<int>(6, this);
	}
};

#endif