#ifndef _DLL_SIMPLE_CALCULATIONS_H_
#define _DLL_SIMPLE_CALCULATIONS_H_
#include <iostream>
#include<windows.h>
#include <fcntl.h>
 
#if defined DLL_EXPORT
#define DECLDIR extern "C" __declspec(dllexport)
#else
#define DECLDIR extern "C" __declspec(dllimport)
#endif
 
DECLDIR int Addition( int a, int b );
DECLDIR int Subtraction( int a, int b );
DECLDIR int Multiplication( int a, int b );
DECLDIR bool IsPEFile(int irfDescripter, IMAGE_DOS_HEADER *prDosHeader);
DECLDIR bool PrintDosHeader(IMAGE_DOS_HEADER *prDosHeader);

#endif