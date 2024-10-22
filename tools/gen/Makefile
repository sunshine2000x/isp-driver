# See LICENSE file for license details.
HOST_CC ?= gcc
GEN := gen
GEN_SRC := $(wildcard tools/gen/*.c)
$(GEN):
	@mkdir -p $(HOST_OUT)
	@$(HOST_CC) $(GEN_SRC) $(CFLAGS) -o $(HOST_OUT)/$@
	@$(HOST_OUT)/$@
