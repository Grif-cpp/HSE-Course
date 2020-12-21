#pragma once

#include "typelist.h"

template<typename TList, typename TargetType>
struct IndexOf;

template<typename TargetType>
struct IndexOf<NullType, TargetType> {
	const static int ind = -1;
};
template<typename Tail, typename TargetType>
struct IndexOf<TypeList<TargetType, Tail>, TargetType> {
	const static int ind = 0;
};
template<typename Head, typename Tail, typename TargetType>
struct IndexOf<TypeList<Head, Tail>, TargetType> {
	const static int next = IndexOf<Tail, TargetType>::ind;
	const static int ind = (next == -1) ? -1 : next + 1;
};
