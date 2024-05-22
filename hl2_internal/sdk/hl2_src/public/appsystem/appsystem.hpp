#pragma once
#ifndef APPSYSTEM_HPP
#define APPSYSTEM_HPP

class AppSystem_t
{
public:
	virtual bool Connect(void* this_ptr) = 0;
	virtual void Disconnect() = 0;
	virtual void* QueryInterface(const char* interface_) = 0;
	virtual int Init() = 0;
	virtual void Shutdown(char* reasons) = 0;
};

#endif