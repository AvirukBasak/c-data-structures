NULL =
TAB = $(NULL)    $(NULL)

# aliased options
all: options
o: options
d: debug
b: build
r: run
c: clean
cf: cleanf

# options for make
options:
	$(info USAGE:)
	$(info $(TAB)make o  | options)
	$(info $(TAB)make d  | debug src="sourcedir")
	$(info $(TAB)make b  | build src="sourcedir")
	$(info $(TAB)make r  | run bin="binpath")
	$(info $(TAB)make c  | clean)
	$(info $(TAB)make cf | cleanf)
	$(info EXAMPLES:)
	$(info $(TAB)make o)
	$(info $(TAB)make d src=stack)
	$(info $(TAB)make b src=stack)
	$(info $(TAB)make r bin=stack)
	$(info $(TAB)make c)
	$(info $(TAB)make cf)
	@exit

# required stuff
CC        = gcc
DBG       = gdb
DBG_FLAGS = -Wall -D DEBUG="(1)" -g3 -ggdb
REL_FLAGS = -Wall -Ofast

SRC_DIR   = ./src
BIN_DIR   = ./bin

GOTO_HELL = 2> /dev/null

# clear screen
clscr:
	clear

# if src path isn't set, exit
src_set:
ifndef src
	$(info src= not set)
	$(info $(TAB)see make options)
	$(error failed)
endif

# create binary path
make_dbg_path:
DBG_PATH = $(BIN_DIR)/dbg/dbg-$(src)

# creates debug build and launches in gdb
debug: src_set clscr make_dbg_path
	mkdir -p $(BIN_DIR)/dbg
	$(CC) $(DBG_FLAGS) $(SRC_DIR)/$(src)/*.c -o $(DBG_PATH)
	$(DBG) $(DBG_PATH)

# create binary path
make_rel_path:
REL_PATH = $(BIN_DIR)/rel/$(src)

# compile source to bin path
build: src_set clscr make_rel_path
	mkdir -p $(BIN_DIR)/rel
	$(CC) $(REL_FLAGS) $(SRC_DIR)/$(src)/*.c -o $(REL_PATH)

# if bin path isn't set, exit
bin_set:
ifndef bin
	$(info bin= not set)
	$(info $(TAB)see make options)
	$(error failed)
endif
bin_prefix = $(shell echo $(bin) | head -c 4)

# run source
run: bin_set
ifeq ($(bin_prefix), dbg-)
	@$(BIN_DIR)/dbg/$(bin)
else
	@$(BIN_DIR)/rel/$(bin)
endif

# clear binaries
clean:
	mkdir -p $(BIN_DIR)
	rm -r $(BIN_DIR)

# force clear binaries
cleanf:
	rm -rf $(BIN_DIR)
