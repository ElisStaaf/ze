all: $(BIN)

RUSTC  = cargo build
MVTOOL = mv

SRC = src/*.rs
TMP = target/debug/ze
BIN = /usr/bin/ze

$(BIN):
	$(RUSTC) $(SRC)
	$(MVTOOOL) $(TMP) $(BIN)
