CC       = gcc
BIN      = solver
OBJDIR   = build
SRCS     = main.c deck.c card.c rank.c suit.c
OBJS     = $(SRCS:%.c=$(OBJDIR)/%.o)
CFLAGS   = -g3 -std=c99 -Wall -Wextra -Wpedantic -O1
RM       = rm -rf

$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $(BIN) -lm

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) -c $< -o $@ $(CFLAGS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	$(RM) $(OBJDIR) $(BIN)
