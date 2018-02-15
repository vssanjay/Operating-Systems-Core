#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

int main()

{
	char string[150],ch,recvString[150];
	int i=0,j=0,fd[2],nbytes,fd2[2],nbytes2;
	pid_t  childpid;
	pid_t childpid2;
	char readbuffer[200], readbuffer2[200];

	printf("Enter your string:	");
	scanf("%[^/n]s",string);
	
	pipe(fd);
	
	if((childpid= fork()) == -1)
	{
		perror("fork");
		
	}
	
	if(childpid ==0)
	
	{
		close(fd[0]);
		write(fd[1],string,(strlen(string)+1));
		
	}
	else
	{
		close(fd[1]);
		nbytes= read(fd[0], readbuffer, sizeof(readbuffer));
		
		while (readbuffer[j])
		
		{
		
		ch = readbuffer[j];

		if (ch>= 'a' && ch <= 'z')
		{
		readbuffer[j] = toupper(readbuffer[j]);
		}
		else if (ch>= 'A' && ch  <= 'Z')
		{
		readbuffer[j]= tolower(readbuffer[j]);
		}
		
		j++;
		}
		for (i=0, j=strlen(readbuffer) +1; i<j; i++)
		{
			recvString[i]=readbuffer[i];
		}
	}
	pipe(fd2);
	
	if((childpid2= fork())== -1)
	{
		perror("Fork");
	}
	
	if(childpid2 ==0)
	{
		close(fd2[0]);
		write(fd2[1],recvString,(strlen(recvString) +1));
	}
	
	else
	{
		close(fd2[1]);
		nbytes2=read(fd2[0], readbuffer2, sizeof(readbuffer2));
		printf("\n Changed case string recieved: %s \n",readbuffer2);
	}
	


}

