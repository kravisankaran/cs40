#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
void stringFix(char *string)
{

	int len = strlen(string);
	
	while(len >= 0)
	{
     if(string[len-1] == '\n')
     {
     		string[len]='\0';
     		len --;
     }// if newline

     else if (string[len-1] == '\r')
     {
     		string[len] = '\0';
     		len --; 
     }// if carriage return

     else
     {	
     	 
     	  break;

     }// 
   //string[len]='\0';
	}

int main(int argc, char **argv)
{

 char * string;




 return 0;
}
