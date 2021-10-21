#include <iostream>
using namespace std;
char* toLowerCase(char* instr)
{	
	int differ = 'A'-'a';
	char ch;
	int ii = strlen(instr);
	for (int i=0; i <ii;i++)
	{
		strncpy(&ch,instr+i,1);
		if (ch>='A' && ch<='Z')
		{
			ch = ch-differ;
			memcpy(instr+i,&ch,1);
		}
	}
	return instr;
}
