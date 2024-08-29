#pragma once

template <typename T>
void iter(T arrayAddr, int arrLen, void (*func)(T &)) {
	for (int i = 0; i < arrLen; i++) func(arrayAddr[i]);
}
