#Mettre en place des condtions

CC = g++

EXEC = main

#Tous les .c
SRC = $(wildcard *.cpp)

#Les .o associés au .c
OBJ = $(SRC:.cpp=.o)

#Mettre en place une condition en fonction du Système
OS = linux


ifeq ($(OS), win)
	SUPP = del
else
	SUPP = rm
endif

all : $(EXEC)

#$< : Dépendance correspondante au .o
%.o : %.cpp
	$(CC) -o $@ -c $< -g

$(EXEC) : $(OBJ)
	$(CC) -o $@ $^ -g


clean :
	$(SUPP) $(OBJ)

mrproper : clean
ifeq ($(OS), win)
	$(SUPP) $(EXEC).exe
else
	$(SUPP) $(EXEC)
endif


#Ne régénère que les .o modifiés
