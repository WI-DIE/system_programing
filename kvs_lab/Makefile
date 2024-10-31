CC = gcc
OPTS = -Wall -g
TARG_STATIC = kvs_static
TARG_DYNAMIC = kvs_dynamic
LIBA = libkvs.a
LIBSO = libkvs.so
LIBSRCS = open.c put.c get.c close.c
OBJS = main.o

static: $(TARG_STATIC)

$(TARG_STATIC): $(OBJS) $(LIBA)
	$(CC) -o $(TARG_STATIC) $(OBJS) $(LIBA) -static

$(LIBA): $(LIBSRCS:.c=.o)
	ar rcs $(LIBA) $^

dynamic: $(TARG_DYNAMIC)

$(TARG_DYNAMIC): $(OBJS) $(LIBSO)
	$(CC) -o $(TARG_DYNAMIC) $(OBJS) -L. -lkvs

$(LIBSO): $(LIBSRCS)
	$(CC) -shared -o $(LIBSO) $(LIBSRCS)

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIBA) $(LIBSO) $(TARG_STATIC) $(TARG_DYNAMIC)
