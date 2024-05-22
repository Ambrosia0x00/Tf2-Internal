#pragma once
#ifndef UNIFORMSTREAM_HPP
#define UNIFORMSTREAM_HPP

class UniformStream_t
{
public:
	virtual void SetSeed(int i) = 0;
	virtual float RandomFloat(float min = 0.0f, float max = 1.0f) = 0;
	virtual int RandomInt(int min, int max) = 0;
	virtual float RandomFloatExp(float min = 0.0f, float max = 1.0f, float exp = 1.0f) = 0;
};


#endif