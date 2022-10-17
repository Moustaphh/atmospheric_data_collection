#include <iostream>
#include"intercept.h"


std::string listen_txrx(void)
{
    int fd;
    char c;
    std::ostringstream oss;


    
    if ((fd = serialOpen ("/dev/ttyS0", 9600)) < 0)
    {
 //           fprintf (stderr, "Unable to open serial device: %s\n", perror (errno)) ;

    }
    
    if (wiringPiSetup () == -1)
    {
   //     fprintf (stdout, "Unable to start wiringPi: %s\n",perror (errno)) ;
    }

    delay (500) ;

	while(1){

	if(serialDataAvail(fd)) 
	{

		c=serialGetchar (fd);
		oss<<c;
		printf("%c",c);
		fflush (stdout) ;

	}
	

   // while (serialDataAvail (fd))
   // {
    //    c=serialGetchar (fd);
      //  oss<<c;
//	std::cout<<oss;
	
//       printf (" -> %3d",c ) ;
//	delay(500);
        
 //       fflush (stdout) ;
    }

    return oss.str();

    // wiringpi.serialPuts(fd,'hello world!');
    
    // serialDataAvail (int fd) ans serialGetchar(in fd) for listening !

}
