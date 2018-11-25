#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>


int main(int argc, char* argv[])
{

 if(argc !=4){
    printf("Not a suitable number of program parameters\n");
    return(1);
 }

 	pid_t childPID;
 	char** argv2;
	childPID = fork();
	if(childPID == -1) // Error
	{ 
		perror("Fork failed"); 
		return 1;
	} 
	else if (childPID == 0) // This is the child
	{ 
		//printf("centrez if execvp\n" );
		argv2 = malloc(argc * sizeof(char*));
		for(int i=0; i<argc; i++)
			argv2[i] = argv[i];
		execvp("./calc", argv2);

		
    }
    else {/* childPID!=0; parent process */
    	//printf("childPID = %d\n",(int)childPID );
	        
		waitpid(childPID,0,0); /* wait for child to exit*/ 
		printf("\ncalculation completed\n");
    }
	 		
	exit (0);

    // Write a child process which execute a process ./calc with  argv[1], argv[2] oraz argv[3] parameteres
    //where argv[1] - first number, argv[2] - operation  (+-x/),  argv[3]  - second number  
    //use table methods to pass argument to the program (argv) 

    
 return 0;
}
