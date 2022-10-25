#include <iostream>
#include"intercept.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include<sstream>

std::string listen_txrx(void){


	int fd, len=0;
	char text[29];
	struct termios options; /* Serial ports setting */

	std::ostringstream oss;

	fd = open("/dev/ttyS0", O_RDWR | O_NDELAY | O_NOCTTY);
	if (fd < 0) {
		perror("Error opening serial port");
	//	return -1;
	}

	/* Read current serial port settings */
	// tcgetattr(fd, &options);
	
	/* Set up serial port */
	options.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
	options.c_iflag = IGNPAR;
	options.c_oflag = 0;
	options.c_lflag = 0;

	/* Apply the settings */
	tcflush(fd, TCIFLUSH);
	tcsetattr(fd, TCSANOW, &options);
	

	/* Read from serial port */
	//memset(text, 0, 29);
	write(fd,"GET",3);
	//std::cout<<"\n Get request sent ! \n";
	
	do
	{

    	memset(text, 0, 29);
	len = read(fd, text, sizeof(text));
	
    	usleep(500000);
	write(fd,"GET",3);
	//std::cout<<"\n Get request sent ! \n";
	//printf("len =  %d",len); 
	} while(len <= 28);
	printf("Received %d bytes\n", len);
        printf("Received string: %s\n", text);
	std::string ret = std::string(text);

	
	close(fd);
	printf("\n closed \n");
	return ret;
}
/*
std::string listen_txrx(void)
{
    int fd;
    char c;
    std::ostringstream oss;
    int rec=0;
    int done_=0;

    
	while(rec<29)
	{
	//	sleep(0.1);
		if (serialDataAvail(fd)!=0){

		c=serialGetchar(fd);
		oss<<c;
		printf("\n c = %d",c);
		std::cout<<"  rec= "<<rec<<"\n";
		rec+=1;
	}

	}
	std::cout<<" \n sorti de la boucle while "; 

    return oss.str();

    // wiringpi.serialPuts(fd,'hello world!');
	    
    // serialDataAvail (int fd) ans serialGetchar(in fd) for listening !

}
*/
