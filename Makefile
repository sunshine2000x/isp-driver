# See LICENSE file for license details.
VER_MAJOR := 0
VER_MINOR := 1

# Project Building Configuration
# Options: ipv, soc
PLATFORM := ipv
# Options: yes, no
HAS_PTHREAD := yes
# Options: yes, no
HAS_TEST := yes
# Options: yes, no
NO_TEST_MAIN := no

ifeq ($(PLATFORM),ipv)
  HAS_PTHREAD = yes
endif

CC ?= gcc
AR ?= gcc-ar
#CC = riscv64-unknown-elf-gcc
#AR = riscv64-unknown-elf-ar
LD := $(CC)

HOST_CC := gcc

OUT := out
INC := include

HOST_OUT := $(OUT)/host

# Project Building Targets
BIN1 := isp-test
LIB1 := libisp.a
LIB2 := libtest.a

# Add module code
SRC = $(wildcard isp/*.c isp/modules/*.c)
ifeq ($(PLATFORM),ipv)
  SRC += $(wildcard ipv/*.c)
else
  SRC += $(wildcard soc/*.c)
endif
OBJ1 := $(patsubst %.c,$(OUT)/obj/%.o,$(SRC))
INC += isp/include

# Add test code
SRC = $(wildcard test/*.c test/isp/*.c)
ifeq ($(PLATFORM),ipv)
  SRC += $(wildcard test/ipv/*.c)
else
  SRC += $(wildcard test/soc/*.c)
endif
ifeq ($(HAS_TEST),yes)
  SRC += $(SRC2)
endif
OBJ2 := $(patsubst %.c,$(OUT)/obj/%.o,$(SRC))
INC += test/include test/isp

ifeq ($(PLATFORM),ipv)
  BIN = $(BIN1)
  OBJ = $(OBJ1) $(OBJ2)
else
  BIN = $(LIB1)
  OBJ = $(OBJ1)
  ifeq ($(HAS_TEST),yes)
    BIN += $(LIB2)
    OBJ += $(OBJ2)
  endif
endif

CFLAGS := $(patsubst %,-I%,$(INC))
CFLAGS += -fPIC -Wall -Werror
# Configure the path to generate all isp test parameters and load for the test
CFLAGS += -DTEST_PARAMS_PATH=\"$(shell pwd)/$(HOST_OUT)\"
ifeq ($(NO_TEST_MAIN),yes)
  CFLAGS += -DNO_TEST_MAIN
endif
ifeq ($(HAS_PTHREAD),yes)
  LDFLAGS += -lpthread
endif

include tools/gen/Makefile

$(OBJ): $(OUT)/obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $< -c -o $@
$(BIN1): $(OBJ)
	@$(LD) $(OBJ) $(LDFLAGS) -o $(OUT)/$@
	@echo "make $@ successfully."
$(LIB1): $(OBJ1)
	@$(AR) -rcs $(OUT)/$@ $(OBJ1)
	@echo "make $@ successfully."
$(LIB2): $(OBJ2)
	@$(AR) -rcs $(OUT)/$@ $(OBJ2)
	@echo "make $@ successfully."
all: $(OBJ) $(BIN) $(GEN)
format:
	@find . -name "*.[ch]" -exec clang-format -i {} \;
	@echo "make $@ successfully."
clean:
	@rm -rf $(OUT)
	@echo "make $@ successfully."
test:
	@$(OUT)/$(BIN1)
.PHONY: test
.DEFAULT_GOAL := all
