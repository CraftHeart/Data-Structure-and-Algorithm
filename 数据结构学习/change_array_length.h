#pragma once
#ifndef CHANGE_ARRAY_LENGTH_H_
#define CHANGE_ARRAY_LENGTH_H_

//change the array length definition
template<class Tc>
void ChangeArrayLength(Tc*& str, int OldLength, int NewLength)
{
	if (NewLength < 0)
		throw ("new length must be >= 0");
	int strSize = Min(OldLength, NewLength);
	Tc* temp = new Tc[strSize];

	copy(str, str + strSize, temp);
	delete[] str;
	str = temp;
}

#endif // !CHANGE_ARRAY_LENGTH_H_
