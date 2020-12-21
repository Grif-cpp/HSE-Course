#pragma once

#include "erase.h"
#include "typelist.h"

template<typename Tlist>
struct NoDuplicates;

template<typename TList>
struct NoDuplicates
{
	typedef TypeList<typename TList::Head,
		typename NoDuplicates<typename EraseAll<typename TList::Tail, typename TList::Head>::NewTypeList>::NewTypeList> NewTypeList;
};
template<>
struct NoDuplicates<NullType> {
	typedef NullType NewTypeList;
};
