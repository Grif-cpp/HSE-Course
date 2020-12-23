#pragma once

#include "typelist.h"

template<typename TList, typename TargetType>
struct Erase {
	typedef  TypeList<typename TList::Head,typename Erase<typename TList::Tail, TargetType>::NewTypeList> NewTypeList;
};
template<typename Tail,typename TargetType>
struct Erase<TypeList<TargetType, Tail>, TargetType> {
	typedef Tail NewTypeList;
};
template<typename TargetType>
struct Erase<NullType, TargetType> {
	typedef  NullType NewTypeList ;
};
