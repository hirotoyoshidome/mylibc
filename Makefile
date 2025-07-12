CFLAGS := -Wall -Wextra -Werror -std=c17
CX := ./src/*.o

.PHONY:	build

.SILENT:
build:
	cd src && \
	gcc $(CFLAGS) -c cx_hashmap.c -o cx_hashmap.o && \
	gcc $(CFLAGS) -c cx_list.c -o cx_list.o && \
	gcc $(CFLAGS) -c cx_string.c -o cx_string.o && \
	gcc $(CFLAGS) -c cx_queue.c -o cx_queue.o && \
	gcc $(CFLAGS) -c cx_stack.c -o cx_stack.o && \
	gcc $(CFLAGS) -c cx_logger.c -o cx_logger.o && \
	gcc $(CFLAGS) -c cx_readcsv.c -o cx_readcsv.o
