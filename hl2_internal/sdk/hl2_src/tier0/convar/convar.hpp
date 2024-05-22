#pragma once
#ifndef CONVAR_HPP
#define CONVAR_HPP

#include"../../public/appsystem/appsystem.hpp"
#include"../../includes/structs.hpp"
struct CharactorSet_t { char set[256]; };

class ConVar;
class IConVar;
class CCommand;
class ConCommand;
class ComCommandBase;


class IConVar
{
public:
	virtual void SetValue(const char* string) = 0;
	virtual void SetValue(float value) = 0;
	virtual void SetValue(int value) = 0;
	virtual const char* GetName(void) const = 0;
	virtual bool IsFlagSet(int flag) const = 0;
};

typedef void(*FnChangeCallBack_t)(IConVar*, const char*, float);
class IConCommandBaseAccessor
{
public:
	virtual bool RegisterConCommandBase(ComCommandBase* pVar) = 0;
};

void ConVar_Register(int flag, IConCommandBaseAccessor* pAccessor = nullptr);

class ConCommandBase
{
public:
	ConCommandBase* m_pNext;
	bool m_bRegistered;
	const char* m_szName;
	const char* m_szString;
	int m_iFlags;
public:
	static ConCommandBase* m_pConCommandBase;
	static IConCommandBaseAccessor* m_pAccessor;
public:
	ConCommandBase(void);
	ConCommandBase(const char* szName, const char* szString = 0, int iFlags = 0);
	virtual ~ConCommandBase(void);
	virtual bool IsCommand(void) const;
	virtual bool IsFlagSet(int flags) const;
	virtual void AddFlags(int flags);
	virtual void RemoveFlag(int flag);
	virtual int GetFlags() const;
	virtual const char* GetName(void) const;
	virtual const char* GetHelpText(void) const;
	virtual bool IsRegistered(void) const;
	virtual int GetDLLIdentifer() const;
	virtual void Create(const char* szName, const char* szString = 0, int flags = 0);
	virtual void Init();
};

class CCommand
{
private:
	enum
	{
		COMMAND_MAX_ARGC = 64,
		COMMAND_MAX_LENGTH = 512,
	};
	int m_iArgc;
	int m_iArgvSize;
	char m_pArgsBuffer[COMMAND_MAX_LENGTH];
	char m_pArgvBuffer[COMMAND_MAX_LENGTH];
	const char* m_szArgv[COMMAND_MAX_ARGC];
public:
	CCommand();
	CCommand(int iArgvC, const char* pArgV);
	bool TokenSize(const char* szCommand, CharactorSet_t* pCharSet = nullptr);
	void Rest();
public:
	int ArgC() const
	{
		return m_iArgc;
	}
	const char** ArgV() const
	{
		return m_iArgc ? (const char**)m_szArgv : 0;
	}
	const char* ArgS() const
	{
		return m_iArgvSize ? &m_pArgsBuffer[m_iArgvSize] : "";
	}
	const char* GetCommandString() const
	{
		return m_iArgc ? m_pArgsBuffer : "";
	}
	const char* operator[](int i) const {
		return Arg(i);
	}
	const char* Arg(int i) const
	{
		if (i < 0 || i >= m_iArgc) return "";
		return m_szArgv[i];
	}

	const char* FindArg(const char* szName) const;
	int FindArgInt(const char* szName, int value);
	static int MaxCommandLength()
	{
		return COMMAND_MAX_LENGTH - 1;
	}
	static CharactorSet_t* DefaultCharSet();
};


class ConVar : public ConCommandBase, public IConVar
{
public:
	ConVar(const char* szName, const char* szValue, int iFlags = 0);
	ConVar(const char* szName, const char* szValue, int iFlags, const char* szString);
	ConVar(const char* szName, const char* szValue, int iFlags, const char* szString,
		bool bMin, float fMin, bool bMax, float fMax);
	ConVar(const char* szName, const char* szValue, int iFlags,
		const char* szString, FnChangeCallBack_t callback);
	ConVar(const char* szName, const char* szValue, int iFlags, const char* szString,
		bool bMin, float fMin, bool bMax, float fMax, FnChangeCallBack_t callback);

	virtual ~ConVar(void);

	virtual bool IsFlagSEt(int iFlag) const;
	virtual const char* GetHelpText(void) const;
	virtual bool IsRegistered(void) const;
	virtual const char* GetName(void) const;
	virtual const char* GetBaseName(void) const;
	virtual int GetSplitScreenPlayerSlot() const;
	unsigned long GetColor(void) const;
	virtual void AddFlags(int iFlags);
	virtual int GetFlags() const;
	virtual bool IsCommand(void) const;
	virtual void SetValue(const char* szValue);
	virtual void SetValue(float fValue);
	virtual void SetValue(int iValue);
	virtual void SetValue(unsigned long lValue);
	virtual void InternalSetValue(const char* szValue);
	virtual void InternalSetFloatValue(float fValue);
	virtual void InternalSetIntValue(int iValue);
	virtual void InternalSetColorValue(unsigned long lValue);
	virtual bool ClampValue(float& fValue);
	virtual void ChangeStringValue(const char* szTempVal, float fOldValue);
	virtual void Create(const char* szName, const char* szValue, int iFlags = 0,
		const char* szString = 0, bool bMin = false, float fMin = 0.0, bool bMax = false, float fMax = false,
		FnChangeCallBack_t callback = 0);

	float GetFloat(void) const;
	float GetInt(void) const;
	bool GetBool() const;
	const char* GetString(void) const;
	const char* GetDefault(void) const;

	void InstallChangeCallback(FnChangeCallBack_t callback);

	struct Value_t
	{
		char* m_pszString;
		int m_iStrLen;
		float m_fValue;
		int m_iValue;
	};

	ConVar* m_pParent;
	const char* m_szDefaultValue;
	Value_t m_vValue;
	bool m_bHasMin;
	float m_fMinVal;
	bool m_bHasMax;
	float m_fMaxVal;
	FnChangeCallBack_t m_fnChangeCallbac;

	char pad_0x0000[0x4];
	ConVar* pNext;
	__int32 bRegistered;
	char* pszName;
	char* pszString;
	__int32 nFlags;
	char pad_0x0018[0x4];
	ConVar* pParent;
	char* pszDefaultValue;
	char* strString;
	__int32 strlen;
	float fValue;
	__int32 nValue;
	__int32 bHasMin;
	float fMinVal;
	__int32 bHasMax;
	float fMaxVal;
	void* fnChangeCallback;
};

class ICvar_t : public AppSystem_t
{
public:
	virtual int AllocateDLLIdentifier() = 0;
	virtual void RegisterConCommand(ConCommandBase* pCommandBase) = 0;
	virtual void UnregistereConCommand(ConCommandBase* pCommandBase) = 0;
	virtual void UnregisterConCommands(int id) = 0;
	virtual const char* GetComandLineValue(const char* szVarName) = 0;
	virtual ConCommandBase* FindCommandBase(const char* szName) = 0;
	virtual const ConCommandBase* FindComandBase(const char* szName) const = 0;
	virtual ConVar* FindVar(const char* szVarName) = 0;
	virtual const ConVar* FindVar(const char* szVarName) const = 0;
	virtual ConCommandBase* FindCommand(const char* szName) = 0;
	virtual const ConCommandBase* FindComand(const char* szName) const = 0;
	virtual ConCommandBase* GetCommands(void) = 0;
	virtual const ConCommandBase* GetComands(void) const = 0;
	virtual void InstallGlobalChangeCallback(FnChangeCallBack_t callback) = 0;
	virtual void RemoveGlobalChangeCallback(FnChangeCallBack_t callback) = 0;
	virtual void CallGlobalChangeCallbacks(ConVar* pVar, const char* szString, float fValue) = 0;
	virtual void InstallConsoleDisplayFunc(void* pAddr) = 0;
	virtual void RemoveConsoleDisplayFunc(void* pAddr) = 0;
	virtual void ConsoleColorPrintf(const Color_t& clr, const char* szFormat, ...) const = 0;
	virtual void ConsolePrintf(const char* szFormat, ...) const = 0;
	virtual void ConsoleDPrintf(const char* szFormat, ...) const = 0;
	virtual void RevertFlaggedConVars(int iFlag) = 0;
	virtual void InstallCVarQuery(void* pQuery) = 0;
	virtual bool IsMaterialThreadSetAllowed() const = 0;
	virtual void QueueMaterialThreadSetValue(ConVar* pVar, const char* szValue) = 0;
	virtual void QueueMaterialThreadSetValue(ConVar* pVar, int iValue) = 0;
	virtual void QueueMaterialThreadSetValue(ConVar* pVar, float fValue) = 0;
	virtual bool HasQueuedMaterialThreadConVarSets() const = 0;
	virtual int ProcessQueuedMaterialThreadConVarSets() = 0;

protected:
	class ICVarIteratorInternal;
public:
	class Iterator
	{
	public:
		inline Iterator(ICvar_t* pVar);
		inline ~Iterator(void);
		inline void SetFirst(void);
		inline void Next(void);
		inline bool IsValid(void);
		inline ConCommandBase* Get(void);
	private:
		ICVarIteratorInternal* m_pIter;
	};
protected:
	class ICVarIteratorInternal
	{
	public:
		virtual ~ICVarIteratorInternal() {}
		virtual void SetFirst(void) = 0;
		virtual void Next(void) = 0;
		virtual bool IsValid(void) = 0;
		virtual ConCommandBase* Get(void) = 0;
	};
	virtual ICVarIteratorInternal* FactoryInternalIterator(void) = 0;
	friend class Iterator;
};

#endif