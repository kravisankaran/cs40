#include "utilities.h"

bool checkforSpace(char * string)
{
  int len = strlen(string)-1;
  int i= 0;
  int ret = 0;
  bool flag = false;
  
  //strcpy(temp, "");
  while(i <= len)
  {
    if(isspace(string[i]))
    {
      ret = 1;
      break;
    }
    i++;
  }
  if(ret == 1)
  {
    flag = true;
  }
  else {flag = false;}
return flag;

}
void stringFix(char *string)
{

	int len = strlen(string);

	while(len >= 0)
	{
     if(string[len-1] == '\n')
     {
     		string[len-1]='\0';
     		len --;
     }// if newline

     else if (string[len-1] == '\r')
     {
     		string[len-1] = '\0';
     		len --; 
     }// if carriage return

     else
     {	
     	 
     	  break;

     }// 
   //string[len]='\0';
	}// while

}// fixing trailing newline and carriage return

int getNumber()
{

   char ch; int ret; int num =0;
   while((ch= getchar())!= '\n') 
   {
    
     if(ch >=48 && ch<=57)
      {
        
        ret= (int) (ch -48) ;
        
      }
      num *=10;
      num += ret;
   }
   
   return num;
}