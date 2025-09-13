g = gcc
fl = -Wall -Wextra -Wpedantic
src = $(wildcard *.c)	# Inlcuding all .c files
obj = $(src:.c=.o) 
target = program

all: $(target) # setting the target

$(target): $(obj)
	$(g) $(obj) -o $(target)

%.o: %.c
	$(g) $(fl) -c $< -o $@

clean:
	rm -f $(obj)

.PHONY: all clean
