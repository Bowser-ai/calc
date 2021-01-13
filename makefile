src_dir=./src
include_dir=./include

calc : $(src_dir)/main.cpp $(src_dir)/calc.cpp $(src_dir)/calc_stream.cpp $(src_dir)/var_table.cpp
	g++ -O2 $^ -o $@ -I$(include_dir)

install:
	cp calc /home/martijn/bin
