#pragma once

#include "typelist.h"

template<typename TList, typename TargetType>
struct EraseAll {
	typedef TypeList<typename TList::Head, typename EraseAll<typename TList::Tail, TargetType>::NewTypeList> NewTypeList;
};
template<typename Tail, typename TargetType>
struct EraseAll<TypeList<TargetType,Tail>,TargetType>{
	typedef  typename EraseAll<Tail, TargetType>::NewTypeList NewTypeList;
};

template<typename TargetType>
struct EraseAll<NullType, TargetType> {
	typedef NullType NewTypeList;
};
