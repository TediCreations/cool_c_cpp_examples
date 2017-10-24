###############################################################################
# Project structure
###############################################################################

BIN_DIR=		bin/
OBJ_DIR=		obj/

###############################################################################
# Toolchain
###############################################################################

BINPATH=		
PREFIX=			

CC=				$(BINPATH)$(PREFIX)gcc
AS=				$(BINPATH)$(PREFIX)gcc -x assembler-with-cpp
CP=				$(BINPATH)$(PREFIX)objcopy
AR=				$(BINPATH)$(PREFIX)ar
SZ=				$(BINPATH)$(PREFIX)size
HEX=			$(CP) -O ihex
BIN=			$(CP) -O binary -S

CFLAGS=			-Isrc\
				-W -Wall -Werror\
				-fdata-sections -ffunction-sections

LFLAGS=			-lm\
				-Wl,--gc-sections

###############################################################################
# Utilities
###############################################################################

# TERMINAL COLORS
RED :=			$(shell tput -Txterm setaf 1)
GREEN :=		$(shell tput -Txterm setaf 2)
WHITE :=		$(shell tput -Txterm setaf 7)
YELLOW :=		$(shell tput -Txterm setaf 3)
RESET :=		$(shell tput -Txterm sgr0)

# Add the following 'help' target to your Makefile
# And add help text after each target name starting with '\#\#'
# A category can be added with @category
# Credits to: https://gist.github.com/prwhite/8168133
HELP_FUNC = \
	%help; \
	while(<>) { \
		if(/^([a-z0-9_-]+):.*\#\#(?:@(\w+))?\s(.*)$$/) { \
			push(@{$$help{$$2}}, [$$1, $$3]); \
		} \
	}; \
	print "Usage: make ${YELLOW}[target]${RESET}\n\n"; \
	for ( sort keys %help ) { \
		print "${WHITE}$$_:${RESET}\n"; \
		printf("  ${YELLOW}%-20s${RESET} ${GREEN}%s${RESET}\n", $$_->[0], $$_->[1]) for @{$$help{$$_}}; \
		print "\n"; \
	}

PASS :=			@tput bold && tput -Txterm setaf 2 && echo "OK" && tput -Txterm sgr0
BUILD_OK :=		@tput bold && tput -Txterm setaf 2 && echo "Build successfully!" && tput -Txterm sgr0

COMP_MSG :=		@tput bold && tput -Txterm setaf 3 && echo -n "Compiling " && tput -Txterm sgr0
MAKE_DIR :=		@tput bold && tput -Txterm setaf 6 && echo -n "Created   " && tput -Txterm sgr0

###############################################################################
# Phony rules
###############################################################################

.PHONY: all
all: ##@options Build everything
all: static_linked_list inheritance_in_c bubble_sort
	@echo
	$(BUILD_OK)
	@echo

.PHONY: clean
clean: ##@options Clean generated files and folders
clean:
	@echo		-n "Cleaning $(TARGET_NAME) project\t"
	@rm			-fR $(OBJ_DIR)
	@rm			-fR $(BIN_DIR)
	$(PASS)
	@echo

.PHONY: help
help: ##@options Shows a list of all available make options.
	@perl -e '$(HELP_FUNC)' $(MAKEFILE_LIST)

###############################################################################
# static_linked_list
###############################################################################

.PHONY: static_linked_list
static_linked_list: ##@C_examples Build linked list with static memory allocation.
static_linked_list: src/static_linked_list/main.c | $(BIN_DIR)
	$(COMP_MSG)
	@echo		-n "$@ \t"
	@$(CC)		-o $(BIN_DIR)$@ $^ $(CFLAGS) $(LDFLAGS) 
	$(PASS)

###############################################################################
# inheritance-in-C
###############################################################################

INHERITANCE_IN_C_SRC =		src/inheritance_in_c/main.c \
							src/inheritance_in_c/AbstractProduct.c \
							src/inheritance_in_c/Book.c \
							src/inheritance_in_c/Product.c \
							src/inheritance_in_c/TravelGuide.c

.PHONY: inheritance_in_c
inheritance_in_c: ##@C_examples Implements inheritance with a primitive way in C!!! (needs -fms-extensions or -std=c11 compiler flag)
inheritance_in_c: $(INHERITANCE_IN_C_SRC) | $(BIN_DIR)
	$(COMP_MSG)
	@echo		-n "$@ \t"
	@$(CC)		-o $(BIN_DIR)$@ $^ -fms-extensions $(CFLAGS) $(LDFLAGS) -Isrc/inheritance-in-C/
	$(PASS)

###############################################################################
# bubble_sort
###############################################################################

.PHONY: bubble_sort
bubble_sort: ##@C_examples Classic bubble sort algorithm.
bubble_sort: src/bubble_sort/main.c | $(BIN_DIR)
	$(COMP_MSG)
	@echo		-n "$@ \t"
	@$(CC)		-o $(BIN_DIR)$@ $^ $(CFLAGS) $(LDFLAGS) 
	$(PASS)

###############################################################################
# Create bin directory
###############################################################################

$(BIN_DIR):
	$(MAKE_DIR)
	@echo		-n "$@ \t"
	@mkdir		-p $@
	$(PASS)

