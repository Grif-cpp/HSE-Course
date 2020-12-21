#pragma once

#include "typelist.h"

template<typename TList>
struct Length {
	static const int length = Length<typename TList::Tail>::length>+1;
};
template<>
struct Length<NullType> {
	static const int length = 0;
};
