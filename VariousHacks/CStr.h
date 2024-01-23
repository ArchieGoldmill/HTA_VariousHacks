#pragma once

struct CStr
{
	char* charPtr;
	int allocSz;
	char zeroChar;

	bool Equal(char* str)
	{
		return this->allocSz && !strcmp(this->charPtr, str);
	}

	bool Equal(const char* str)
	{
		return this->allocSz && !strcmp(this->charPtr, str);
	}
};