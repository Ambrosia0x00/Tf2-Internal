#pragma once
#ifndef NETVAR_HPP
#define NETVAR_HPP

namespace I
{
	BaseClient_t* BaseClient = nullptr;
}

class NetVar
{
public:
	int GetOffset(RecvTable* pTable, const char* szVarName);
	int GetNetVar(const char* szClass, const char* szVarName);
}; inline NetVar* pNetVar;

inline int NetVar::GetOffset(RecvTable* pTable, const char* szVarName)
{
	for (int i = 0; i < pTable->m_nProps; i++)
	{
		const auto Prop = pTable->m_pProps[i];
		if (strcmp(szVarName, Prop.m_pVarName) == 0)
			return Prop.GetOffset();

		if (const auto pDataTable = Prop.GetDataTable())
		{
			if (const auto nOffset = GetOffset(pDataTable, szVarName))
				return nOffset + Prop.GetOffset();
		}
	}
	return 0;
}

inline int NetVar::GetNetVar(const char* szClass, const char* szVarName)
{
	ClientClass_t* pClientClass = I::BaseClient->GetAllClasses();
	while (pClientClass)
	{
		if (strcmp(szClass, pClientClass->GetName()) == 0)
			return GetOffset(pClientClass->m_pNext, szVarName);
		pClientClass = pClientClass->m_pClass;
	}
	return 0;
}

#endif