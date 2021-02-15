CC=g++
SOURCEFILES = main.cpp hello.cpp factorial.cpp
EXE = hello
INSTALL_DIR = ./bin

default: 
	$(CC)  $(SOURCEFILES) -o $(EXE)

clean:
	rm $(INSTALL_DIR)/$(EXE)

install:
	mv $(EXE) ./bin
