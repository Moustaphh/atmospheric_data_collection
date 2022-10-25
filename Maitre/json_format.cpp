#include"intercept.h"
#include<ctime>



std::string to_json(std::vector<std::string> v)
{   
    std::ostringstream oss;
	

      std::time_t time_ = std::time(0);   // temps actuel
      std::tm* now = std::localtime(&time_);//temps local
      int year= (now->tm_year + 1900);
      int month=now->tm_mon+1;
      int day=now->tm_mday;
      int hour=now->tm_hour;
      int min=now->tm_min;

    oss<<"WW{ \n";
    oss<<" \"annee\" : "<<"\""<<year<<"\"";
    oss<<"\n,\"mois\" : "<<"\""<<month<<"\"";
    oss<<"\n,\"jour\" : "<<"\""<<day<<"\"";
    oss<<"\n,\"heure\" : "<<"\""<<hour<<"\"";
    oss<<"\n,\"minute\" : "<<"\""<<min<<"\"";
  //  oss<<" \"seconde\" : "<<"\""<<v[5];
    
    oss<<"\n, \"temperature\" : "<<"\""<<v[0]<<"\"";
    oss<<"\n,\"humidite\" : " <<"\""<<v[1]<<"\"";
    oss<<"\n,\"pression\" : "<<"\""<<v[2]<<"\"";
    oss<<"\n,\"x\" : "<<"\""<<v[3]<<"\"";
    oss<<"\n,\"y\" : "<<"\""<<v[4]<<"\"";
    oss<<"\n,\"z\" : "<<"\""<<v[5]<<"\"";
    oss<<"\n }\n";
    std::string s = oss.str();

    return s;

}


void blink_led(int led, int time) {

    digitalWrite(led, HIGH);
    delay(time);
    digitalWrite(led, LOW);
    delay(time);
    digitalWrite(led, HIGH);
    delay(time);
    digitalWrite(led, LOW);
    delay(time);

}

std::vector<std::string> parse_it(std::string s )
{
    char delim=' ';
    std::stringstream ss(s);
    std::string s2;  
    std::vector<std::string> out;
    while (std:: getline (ss, s2, delim) )  
    {  
        out.push_back(s2); // store the string in s2  
    }
    return out;  

}

// this is for testing 
// int main(){

//     std::vector<std::string> v{"temp","hum", "p","x","y","z"};

//     std::cout<<to_json(v);
//     return 0;
// }
