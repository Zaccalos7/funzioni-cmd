#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0

#define MAX_LEN_STRING_INPUT 3


char *cmd_list[]={"LED","STATUS"};
char *parameter_list[]={"RED","BLUE","GREEN","ON","OFF"};
char *token;
bool find=FALSE;


int count_word_string(char* cmd)
{
    int len=strlen(cmd);
    int count_word=0;
    
    for(int i=0;i<len;i++)
    {
        if(cmd[i]==' ')
        {
            count_word++;
        }else if(cmd[i+1]=='\0')
            {
                count_word++;
            }
    }
    
    return count_word;
}




bool check_cmd(char* test, int len)
{
    token=strtok(test," ");
    
    for(int i=0; i<len;i++)
    {
        if(strcmp(token,cmd_list[i])==0)
        {
        
        find=TRUE;
        int size=strlen(cmd_list[i]);
        char do_cmd[size+1];
        strcpy(do_cmd,cmd_list[i]);
        printf("do_cmd=%s\n",do_cmd);

        } 
    }
    
    return find;
}

void check_parameter(char *test,int len)
{
    //cut the head with command
   //length minus one
    token=strtok(test," ");
    token=strtok(NULL," ");
    len--;
    
    for(int i=0; i<len;i++)
    {
        if(strcmp(token,cmd_list[i])==0)
        {
        
        } 
    }
    
}

int main()
{
    char test[]={"LED ON BLUE"};
   

    
    while(1)
    {
        int words_serial=count_word_string(test);
        //stop and restart loop
        if(words_serial>MAX_LEN_STRING_INPUT)
        {
            continue;
        }

        if(find==FALSE)
        check_cmd(test,words_serial);
            else if(find==TRUE)
            {
                check_parameter(test,words_serial);
                break;
            }else{}
    }
    return 0;
}