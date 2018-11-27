#ifndef _DLL_TEST_Header_H_
#define _DLL_TEST_Header_H_
#include <iostream>
 
#ifdef DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif
 
extern "C"
{
	DECLDIR int Add( int a, int b );
	DECLDIR bool DisplayAddition(int c);
	DECLDIR void Function( void );
}
 
#endif