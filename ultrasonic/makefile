OBJS		= Ultrasonic.o
SOURCE		= Ultrasonic.cpp
HEADER		= 
OUT			= libultrasonic.a
CC			= /usr/local/oecore-x86_64/sysroots/x86_64-nilrtsdk-linux/usr/bin/arm-nilrt-linux-gnueabi/arm-nilrt-linux-gnueabi-g++ 
CFLAGS		= --sysroot=/usr/local/oecore-x86_64/sysroots/cortexa9-vfpv3-nilrt-linux-gnueabi -std=c++11 -pthread
INCLUDE 	= -I../../myrio/myrio -I../../myrio/myrio/csupport -I"/usr/local/oecore-x86_64/sysroots/cortexa9-vfpv3-nilrt-linux-gnueabi/usr/include" -I"/usr/local/oecore-x86_64/sysroots/cortexa9-vfpv3-nilrt-linux-gnueabi/usr/include/c++/4.9.2/arm-nilrt-linux-gnueabi" 
FLAGS		= -g -c -Wall -DMyRio_1900 -O0 -g3 -Wall -std=gnu++11 -fmessage-length=0 -mfpu=vfpv3 -mfloat-abi=softfp
LFLAGS 		= -ldl


all: $(OBJS)
	ar cr $(OUT) $(OBJS)

Ultrasonic.o: Ultrasonic.cpp
	$(CC) $(CFLAGS) $(INCLUDE) $(FLAGS) Ultrasonic.cpp


clean:
	rm -f $(OBJS) $(OUT)



