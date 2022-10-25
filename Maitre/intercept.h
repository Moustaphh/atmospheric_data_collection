#ifndef HEADER_INTERCEPT
#define HEADER_INTERCEPT

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include <wiringPi.h>
#include<wiringSerial.h>
#include<errno.h>
#include<stdio.h>

#define PORT 8080


std::string listen_txrx(void);
void blink_led(int led, int time);
std::string to_json(std::vector<std::string>);
std::vector<std::string> parse_it(std::string);
int send_tcp(std::string);

#endif

