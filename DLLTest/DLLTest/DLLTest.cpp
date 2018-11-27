#include <iostream>
#include "DLLTestHeader.h"
 
#define DLL_EXPORT
#define DLL_IMPORT
 
extern "C"
{
	DECLDIR int Add( int a, int b )
	{
		return( a + b );
	}

	DECLDIR bool DisplayAddition( int c )
	{
		printf("Result of Addition is : %d ", c);
		return true;
	}

	DECLDIR void Function( void )
	{
		std::cout << "DLL Called!" << std::endl;
	}
}