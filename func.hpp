#pragma once
#include <iostream>

namespace func {
	using namespace std;
	template<typename Base, typename T>
	inline bool instanceof(const T*) {
		return std::is_base_of<Base, T>::value;
	}
}