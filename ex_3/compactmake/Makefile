g = gcc # variable for gcc compiler
fl = -Wall -Wextra -Wpedantic  # compiler flags(for warning and pedantic checks )
src = $(wildcard *.c)	# Inlcuding all .c files in the current directory
obj = $(src:.c=.o) # This represents the object files. This command replaces all .c files with .o (main.c, random.c --> main.o, random.o). But here this not creating object files, just renaming them. 

target = program # 'program' is the name of final executable file

all: $(target) # Setting the target to be 'program', which depends on $(target)

$(target): $(obj)  # To build $(target), we need all object files
	$(g) $(obj) -o $(target) # This links all the object files into the final executable 'program'

%.o: %.c
	$(g) $(fl) -c $< -o $@ 
# This is the place where actual .o files are created. Here both < and @ are automatic variables. $< refers to the input .c files. $@ refers to the output .o file.

clean:
	rm -f $(obj) # Removing the object files

.PHONY: all clean # Declaring 'all' and 'clean' as phony, avoid conflicts with actual files
