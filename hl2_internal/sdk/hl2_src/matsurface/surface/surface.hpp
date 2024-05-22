#pragma once
#ifndef SURFACE_HPP
#define SURFACE_HPP
#include"../../utils/vfunc/vfunc.hpp"

enum FontDataType_t
{
	FONT_DRAW_DEFAULT = 0,
	FONT_DRAW_NONADDITIVE,
	FONT_DRAW_ADDITIVE,
	FONT_DRAW_TYPE_COUNT = 2,
};

namespace vgui
{
	typedef unsigned long HCursor;
	typedef HCursor HTexture;
	typedef HCursor HFont;
	typedef unsigned int VPanel;
}

typedef struct CharRenderInfo_t
{
	int x, y, textureId, abcA, abcB, abcC, fontTall;
	vgui::HFont currentFont;
	FontDataType_t drawType;
	wchar_t ch;
	bool valid;
	bool shouldClip;
};

typedef struct IntRect_t
{
	int x0, y0, x1, y1;
};

enum SurfaceFeature_t
{

};

class MatSystemSurface_t
{
public:
	void SetCursorAlwaysVisible(bool null)
	{
		return pFunc->CallVFunc<void>(52, this, null);
	}
	bool IsCursorVisible()
	{
		return pFunc->CallVFunc<bool>(53, this);
	}
	void UnlockCursor()
	{
		return pFunc->CallVFunc<void>(61, this);
	}
	void LockCursor()
	{
		return pFunc->CallVFunc<void>(62, this);
	}
};

#endif