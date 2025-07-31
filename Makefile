CFLAGS = -Wall -Wextra -Werror -std=c17

SRCDIR = src
OBJDIR = obj

SRCS := $(wildcard $(SRCDIR)/*.c)
OBJS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

.PHONY:	build	clean	test

.SILENT:
build: $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)


test:
	$(CC) $(CFLAGS) -I./src -c tests/main.c -o tests/main.o
	$(CC) $(CFLAGS) -o tests/test tests/main.o obj/*.o
	./tests/test
	rm ./tests/test ./tests/*.o || true
