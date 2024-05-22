#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include<unordered_map>
#include"../interfaces/interfaces.hpp"

class Globals
{
public:
	std::unordered_map<BaseEntity_t*, int> entities;
	int local_player;
public:
	int local_health;
	int entity_health;
}; inline Globals* pGlobals;

#endif