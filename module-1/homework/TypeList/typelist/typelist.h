#pragma once

struct NullType {};

template<typename head, typename tail>
struct TypeList {
	typedef head Head;
	typedef tail Tail;
};
