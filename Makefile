PREFIX ?=

CC	= $(PREFIX)gcc
CPP	= $(PREFIX)g++
AS	= $(CC)
LD	= $(PREFIX)ld
AR	= $(PREFIX)ar

ROOT = ./../

LIB := -L$(ROOT)/lib-pca9685/lib_linux
LDLIBS := -lpca9685 
LIBDEP := $(ROOT)/lib-pca9685/lib_linux/libpca9685.a

INCLUDES := -I$(ROOT)/lib-pca9685/include

COPS := -Wall -O3 -fno-rtti -std=c++11 -DNDEBUG

BCM2835 = $(ROOT)/lib-bcm2835_raspbian

ifneq "$(wildcard $(BCM2835) )" ""
	LIB += -L$(BCM2835)/lib_linux
	LDLIBS += -lbcm2835_raspbian
	INCLUDES += -I$(BCM2835)/include
else
	LDLIBS += -lbcm2835
endif

all : spider_coar

clean :
	rm -f *.o
	rm -f /build/logs/*.lst
	rm -f /build/Spider_coar.out
	cd $(ROOT)/lib-pca9685 && make -f Makefile.Linux clean
	
$(ROOT)/lib-pca9685/lib_linux/libpca9685.a :
	cd $(ROOT)/lib-pca9685 && make -f Makefile.Linux "DEF=-DRASPPI"
	
spider_coar : Makefile Spider_firmware.cpp $(ROOT)/lib-pca9685/lib_linux/libpca9685.a
	$(CPP) Spider_firmware.cpp legPart.o leg.o menu.o mainMenu.o spiderControllMenu.o changeLegAngleMenu.o legChooseMenu.o controller.o spider.o $(INCLUDES) -I Include  $(COPS) -o build/Spider_coar.out $(LIB) $(LDLIBS)
	$(PREFIX)objdump -D build/Spider_coar.out | $(PREFIX)c++filt > build/logs/spider_coar.lst

legPart.o: LegPart.cpp $(ROOT)/lib-pca9685/lib_linux/libpca9685.a
	$(CPP) -c LegPart.cpp $(INCLUDES) -I Include $(COPS) -o legPart.o $(LIB) $(LDLIBS)

leg.o: Leg.cpp
	$(CPP) -c Leg.cpp $(INCLUDES) -I Include $(COPS) -o leg.o $(LIB) $(LDLIBS)

menu.o: Menu.cpp
	$(CPP) -c Menu.cpp $(INCLUDES) -I Include $(COPS) -o menu.o $(LIB) $(LDLIBS)

mainMenu.o: MainMenu.cpp
	$(CPP) -c MainMenu.cpp $(INCLUDES) -I Include $(COPS) -o mainMenu.o $(LIB) $(LDLIBS)

spiderControllMenu.o: SpiderControllMenu.cpp
	$(CPP) -c SpiderControllMenu.cpp $(INCLUDES) -I Include $(COPS) -o spiderControllMenu.o $(LIB) $(LDLIBS)

changeLegAngleMenu.o: ChangeLegAngleMenu.cpp
	$(CPP) -c ChangeLegAngleMenu.cpp $(INCLUDES) -I Include $(COPS) -o changeLegAngleMenu.o $(LIB) $(LDLIBS)

legChooseMenu.o: LegChooseMenu.cpp
	$(CPP) -c LegChooseMenu.cpp $(INCLUDES) -I Include $(COPS) -o legChooseMenu.o $(LIB) $(LDLIBS)

controller.o: Controller.cpp
	$(CPP) -c Controller.cpp $(INCLUDES) -I Include $(COPS) -o controller.o $(LIB) $(LDLIBS)

spider.o: Spider.cpp
	$(CPP) -c Spider.cpp $(INCLUDES) -I Include $(COPS) -o spider.o $(LIB) $(LDLIBS)

