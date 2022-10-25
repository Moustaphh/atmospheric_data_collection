#include"intercept.h"
#include<unistd.h>
int main()
{
 if(wiringPiSetupGpio() == -1) { //when initialize wiringPi failed, print message to screen
                printf("setup wiringPi failed !\n");
                return -1;
        }
	int red=26;
	int yellow=19;
	int green=13;
    	pinMode (red, OUTPUT);
	pinMode (yellow, OUTPUT);
	pinMode (green, OUTPUT);
	digitalWrite(yellow, HIGH);

    while(true)
    {
        std::string mystring=listen_txrx();
	digitalWrite(yellow, LOW);
	blink_led(red,300);
	digitalWrite(yellow, HIGH);
//	std::cout<<"\n"<<mystring<<" the problem is not in listen !!\n";

//        std::string mystring{"20 12 14 5 69 5"};
        std::vector<std::string> values=parse_it(mystring);
        std::string json_form=to_json(values);
        std::cout<<json_form<<std::endl;
	digitalWrite(yellow, LOW);
	send_tcp(json_form);
	digitalWrite(green, HIGH);
       	delay(1000);
	digitalWrite(green, LOW);
	digitalWrite(yellow, HIGH);
	std::cout<<"\n sent ! \n ";
	sleep(900);



    }


}
