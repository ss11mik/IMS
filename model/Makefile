# file: code Makefile
# project: "SHO ve výrobě"
# course: IMS
# authors: xmikul69, zpodes05
#   @ VUT FIT, Brno
# date: 2021
#

BINARY=ims
OUTPUT=model.out
CFLAGS = -std=c++17 -Wall -Werror -Wunused-function -Wreturn-type -Wunused-variable -lsimlib -lm
SRCFILES = main.cpp operations.cpp operations.hpp operation.hpp

all:
	g++ $(SRCFILES) -o $(BINARY) $(CFLAGS)

clean:
	rm $(BINARY) $(OUTPUT) | true
