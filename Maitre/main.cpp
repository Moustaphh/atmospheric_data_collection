#include"intercept.h"


int main()
{
    while(true)
    {
        // std::string mystring=listen_txrx();
        std::string mystring{"20 12 14 5 69 5"}
        std::vector<std::string> values=parse_it(mystring);
        std::string json_form=to_json(values);
        std::cout<<json_form<<std::endl;
        int sent=send_tcp(json_form);
    }

}

