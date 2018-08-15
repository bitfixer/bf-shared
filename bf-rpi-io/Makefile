REMOTE := raspberrypi.local

%.o : %.cpp
	g++ -std=c++11 -c $^

bf-rpi-io.a: wPiGPIO.o wPiSPI.o
	ar rcs $@ $^

clean:
	rm -f *.o *.a

transfer:
	scp *.cpp pi@$(REMOTE):~/bf-rpi-io/
	scp *.h pi@$(REMOTE):~/bf-rpi-io/
	scp Makefile pi@$(REMOTE):~/bf-rpi-io/