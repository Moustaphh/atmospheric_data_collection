#include"bme280.h"
#include<string>
#include<iostream>
#include"libSensor.h"
#include <fcntl.h>
#include <unistd.h>
// #include <wiringPi.h>
// #include<wiringSerial.h>
#include<vector>
#include<errno.h>
#include<stdio.h>
#include <cstring>
#include<termios.h>
int main(){

	while(true)
	{
        int fd, len=0;
        char text[3];
        struct termios options; /* Serial ports setting */


        fd = open("/dev/ttyS0", O_RDWR | O_NDELAY | O_NOCTTY);
        if (fd < 0) {
                perror("Error opening serial port");
        //      return -1;
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
        do
        {
        memset(text, 0, 3);
        len = read(fd, text, sizeof(text));
        
        usleep(500000);
        
       // printf(" received  =  %s",text); 
        } while(len <= 2);


        if(text[0]=='G' && text[1]=='E' && text[2]=='T')
        {

    


        std::string vals= get_measurements();
        std::string vals1=get_acc();
        std::string all_vals=vals + vals1;
        std::vector<std::string> v=format_data(all_vals);
        
        std::cout<<"\n"<<all_vals<<"\n";
        //1=>2  2=>2 3=>2 4=>2  5=>2 6=>2 7=>4 8=>4 9=>6 10=>2 11=>2 12=>2
        int numbers[]={5,6,7,2,2,2};
        for(int i =0 ;i<v.size();i++)
        {
    //		if(v[i].length()<numbers[i])
    //		{
                while(v[i].length()<numbers[i]){
                v[i]=v[i]+'0';
            }

        }
        
        std::string to_send=v[0];

        for(int j=1;j<v.size();j++){

        to_send+=" "+v[j];
        }
        
        int len= to_send.length();
        std::cout<<"\n to send :   "<<to_send;
        std::cout<< "\n  length = "<<len<<"\n";
        const char* str_ = to_send.c_str();

        
        int Size = strlen(str_);
        std::cout<<"\n char * size = "<<Size;
  
        // serialFlush (fd) ;
        write(fd,str_,len);


        }


    close(fd);
	

}}
