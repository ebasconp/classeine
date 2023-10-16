
all:
	make -C code/classeine-demo

clean:
	make clean -C code/classeine-demo

run: all
	make all -C code/classeine-demo