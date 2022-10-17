#include"intercept.h"




std::string to_json(std::vector<std::string> v)
{   
    std::ostringstream oss;

    oss<<"{ \"measurement\":[{ \n";

    oss<<" \"temp\" : "<<"\""<<v[0]<<"\"";
    oss<<"\n,\"humidite\" : " <<v[1];
    oss<<"\n,\"pression\" : "<<v[2];
    oss<<"\n,\"x\" "<<v[3];
    oss<<"\n,\"y\" : "<<v[4];
    oss<<"\n,\"z\" : "<<v[5];
    oss<<"\n }]\n";
    std::string s = oss.str();

    return s;

}


void blink_led(int led, int time) {
    digitalWrite(led, HIGH);
    delay(time);
    digitalWrite(led, LOW);
    delay(time);
}

std::vector<std::string> parse_it(std::strings s )
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