// SimpleCalculations.cpp : Defines the exported functions for the DLL application.
//
#include <stdio.h>
#include "stdafx.h"
#include<windows.h>
#include <fcntl.h>
#include<io.h>
#include "DLLSimpleCalculations.h"
 
#define DLL_EXPORT

int
Addition(int a, int b)
{
	return (a + b);
}

int Subtraction(int a, int b)
{
	return (a - b);
}

int Multiplication(int a, int b)
{
	return (a * b);
}

bool
IsPEFile(
	int irfDescripter, 
	IMAGE_DOS_HEADER* prDosHeader
	)
{
	int icRead=0;
	
	icRead = _read(irfDescripter,prDosHeader, sizeof(IMAGE_DOS_HEADER));
	if(icRead != sizeof(IMAGE_DOS_HEADER))
	{
		printf("\nError in reading........!!!!!!\n");
		return false;
	}
	
	if (0x5A4D == prDosHeader -> e_magic)
	{
		printf("\nFile is Portable Executable\n");
		return true;
	}
	else
	{
		printf("\nFile s not Portable Executable ");
		return false;
	}
	

}

bool
PrintDosHeader(
	IMAGE_DOS_HEADER *prDosHeader
	)
{
	printf("\nDosHeader");
	printf("\nMagic no:  %x",prDosHeader->e_magic);
	printf("\nE_Ifanew : %x",prDosHeader->e_lfanew);
	printf("\n------------------------------Dumping DOS Header Info--------------------------");
	printf("\n%-36s%s ","Magic number : ",prDosHeader->e_magic==0x5a4d?"MZ(Mark Zbikowski)":"-");
	printf("\n%-36s%#x","Bytes on last page of file :",prDosHeader->e_cblp);
	printf("\n%-36s%#x","Pages in file : ",prDosHeader->e_cp);
	printf("\n%-36s%#x","Relocation : ",prDosHeader->e_crlc);
	printf("\n%-36s%#x","Size of header in paragraphs : ",prDosHeader->e_cparhdr);
	printf("\n%-36s%#x","Minimum extra paragraphs needed : ",prDosHeader->e_minalloc);
	printf("\n%-36s%#x","Maximum extra paragraphs needed : ",prDosHeader->e_maxalloc);
	printf("\n%-36s%#x","Initial (relative) SS value : ",prDosHeader->e_ss);
	printf("\n%-36s%#x","Initial SP value : ",prDosHeader->e_sp);
	printf("\n%-36s%#x","Checksum : ",prDosHeader->e_csum);
	printf("\n%-36s%#x","Initial IP value : ",prDosHeader->e_ip);
	printf("\n%-36s%#x","Initial (relative) CS value : ",prDosHeader->e_cs);
	printf("\n%-36s%#x","File address of relocation table : ",prDosHeader->e_lfarlc);
	printf("\n%-36s%#x","Overlay number : ",prDosHeader->e_ovno);
	printf("\n%-36s%#x","OEM identifier : ",prDosHeader->e_oemid);
	printf("\n%-36s%#x","OEM information(e_oemid specific) :",prDosHeader->e_oeminfo);
	printf("\n%-36s%#x","RVA address of PE header : ",prDosHeader->e_lfanew);
	printf("\n===============================================================================\n");
	return true;
}
