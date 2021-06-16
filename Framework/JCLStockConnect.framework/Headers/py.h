#pragma once

#include <map>

constexpr int MAX_SPELL_NUM = 4;

typedef struct
{
	const char* traditional_;
	const char* spell_[MAX_SPELL_NUM];
}SpellInfo;

extern const std::map<wchar_t, SpellInfo> g_spell;
