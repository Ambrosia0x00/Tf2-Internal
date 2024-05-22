#pragma once

#include"../../utils/hooker/hooker.hpp"
#include"../../interfaces/interfaces.hpp"

typedef int(__fastcall* Stream_t)(UniformStream_t*, int, int);
Stream_t streamFn = 0;

namespace Uniformstream
{
	namespace RandomInt
	{
		size_t index = 2;
		int __fastcall Detour(int min, int max)
		{
			static bool flip_medal = true;
			if (flip_medal && I::EngineVGui->IsGameUIVisable())
			{
				if (min == 0 && max == 9)
					return 0;
			}
			return streamFn(I::UniformStream, min, max);
		}
	}

	void Initialize()
	{
		streamFn = (Stream_t)pHook->vmt_hook(I::UniformStream, RandomInt::index,
			(uintptr_t)RandomInt::Detour);
	}
}