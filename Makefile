all: $(BIN)

RUSTC  = rustc
RFLAGS = -o

SRC = src/*.rs
BIN = /usr/bin/ze

$(BIN):
	$(RUSTC) $(RFLAGS) $(BIN) $(SRC)
