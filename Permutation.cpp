#include "Permutation.h"

Permutation::Permutation(int a[4])
{
	for (int i = 0; i < 4; i++) {
		perm[i] = a[i];
	}
}

int Permutation::getElem(int a)
{
	return perm[a];
}
