#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>



#define limit 256
#define maxline 1024
#define maxhist 1000
int no_reprint;
int changeDirectory(char *args[]);
int commandHandler(char *args[]);
char* hist[maxhist];
int new_command_no;
char* curr_dir;
char last_dir[1024];
char home[1024];

void welcome()
{
    printf("\n\t================================================\n");
    printf("\t   Interactive shell in c\n");
    printf("\t      Roll No.: 2021102032\n");
    printf("\t================================================\n");
    printf("\n\n");
    return;
}

//-------------shell prompt initilization-------------
void shellPrompt()
{
    // We print the prompt in the form "<user>@<host> <cwd> >"
    char hostn[1204] = "";
    gethostname(hostn, sizeof(hostn));
    printf("%s@%s %s > ", getenv("LOGNAME"), hostn, getcwd(curr_dir, 1024));
    strcpy(last_dir,curr_dir);
    strcpy(home,curr_dir);
}




/// -------------implementation of history command  

int isDigit(char *s)
{
	int i;
	for (i = 0; s[i]; ++i)
		if((int)(s[i]) <48 || (int)(s[i]) >57) return 0;
	return 1;
}

int history(char **args)
{
  if (args[1] == NULL || !isDigit(args[1])) {
	printf("invalid argument: expected argument for no of previous commands");
    printf("\n");
  }
 else {
	int cur_cmd = new_command_no;
	int argument = atoi(args[1]);
	int x2 = (new_command_no-argument);
	if( argument > new_command_no){
		//that is if unsufficient number of commands are there then it will print all commands available.
		x2 = 0;
	}
	int i = 0;
	for (i = x2; i < cur_cmd && i >= 0 ; ++i){
		printf("%s\n",hist[i]);
	}  	
 }
  return 1;
}


///---- change directory
int changedir(char* args[]){
	// If we write no path (only 'cd'), then go to the home directory
    char* path;
	if (args[1] == NULL) {
		path=(getenv("HOME")); 
	}
    else if(args[1][0]=='-'){
        path=last_dir;
       
    }
    // else if(args[1][0]=='~'){
      
    //     path=home;
       
    // }
    else path=args[1];
     char temp_str[1024];
    getcwd(temp_str,1024);

	int e=chdir(path);
    if(e<0){

        printf("%s no such directory\n",args[1]);
    }
    else{
        strcpy(last_dir,temp_str);
    }
	return e;
}

int commandhandler(char* args[]){
    
    if(strcmp(args[0],"exit")==0){
        exit(0);
    }
    else if(strcmp(args[0],"pwd")==0){
     
        printf("%s\n",getcwd(curr_dir,1024));
    }
    
    else if(strcmp(args[0],"history")==0){
        history(args);
    }
    else if(strcmp(args[0],"cd")==0){
        changedir(args);
    }
    
    

}

char *username()
{
    char *user = getlogin();
    return user;
}
void do_pwd()
{

    char d[10000];
    getcwd(d, sizeof(d));
    printf("%s\n", d);
    return;
}
char *rmv(char *tok)
{
    size_t len = strlen(tok);
    while (len > 0 && isspace(tok[len - 1]))
    {
        tok[--len] = '\0';
    }
    return tok;
}

int main(int argc,char* argv[])
{
    char line[maxline];
    char* tokens[limit];
    int numtokens;
    char linecopy[maxline];
    no_reprint=0;
    curr_dir=(char* )calloc(1024,sizeof(char));
    welcome();
    int command_no=0;
        
         int t=1;
    while(t){
        if(!no_reprint){
            shellPrompt();
        }
        no_reprint=0;
        memset(line,'\0',maxline);
        fgets(line,maxline,stdin);
        strcpy(linecopy,line);
        if((tokens[0] = strtok(line," \n\t")) == NULL) continue;//
       
        numtokens=1;
        while((tokens[numtokens]=strtok(NULL," \n\t"))!=NULL)numtokens++;
        

        if(strcmp(tokens[0],"history")!=0 && strcmp(tokens[0],"issue")!=0){
            hist[command_no]=(char*)malloc(maxline*sizeof(char));
            strcpy(hist[command_no],linecopy);
            command_no=(command_no+1)%maxhist;
            new_command_no=command_no;
        }

        if(strcmp(tokens[0],"echo")){
        commandhandler(tokens);
        }
        else{
            int s=1;
            if(strchr(linecopy,'"')){
               
                 const char delimiters[] = "\""; 
                 char *ans = strtok(linecopy, delimiters);
                 ans= strtok(NULL, delimiters);
                 printf("%s\n",ans);
            }
            else{
                for(int i=1;i<numtokens;i++){
                    printf("%s ",tokens[i]);
                }
                printf("\n");
            }


        }
    

    }
    
    return 0;
}
