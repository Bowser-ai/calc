calc : main.cpp calc.cpp 
	g++ -O2 $^ -o $@

install:
	cp calc /home/martijn/bin
