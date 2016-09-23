.PHONY: all escape colors image

all:
	$(MAKE) escape
	$(MAKE) colors
	$(MAKE) image

escape:
	g++ -std=c++11 -o escape escape.cpp

colors:
	g++ -std=c++11 -o colors colors.cpp

image:
	g++ -std=c++11 -o image image.cpp

run:
	./escape
	./colors
	./image

clean:
	rm *.escape *.colors *.ppm *.png escape colors image

