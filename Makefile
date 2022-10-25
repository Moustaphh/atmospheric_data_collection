.PHONY: clean

bme280: bme280.cpp bme280.h
	g++ -g -Wall -Wextra -pedantic -std=c++11 -D_DEFAULT_SOURCE -D_BSD_SOURCE -o balise bme280.cpp balise.cpp libSensor.cpp libSensorSample.cpp -lwiringPi -lm

clean:
	rm balise
