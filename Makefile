################################################################################
#                                  PROJECT                                     #
################################################################################

NAME        := libftpp
LIB_DIR     := lib
LIBRARY     := $(LIB_DIR)/$(NAME).a

################################################################################
#                                 COMPILER                                     #
################################################################################

CXX         := c++
AR          := ar
ARFLAGS     := rcs

MODE        ?= debug

CXXFLAGS    := -Wall -Wextra -Werror -std=c++20
CPPFLAGS    := -Iinclude

ifeq ($(MODE),debug)
	CXXFLAGS += -O0 -g3 -DDEBUG
else
	CXXFLAGS += -O2 -DNDEBUG
endif

################################################################################
#                                 DIRECTORIES                                  #
################################################################################

SRC_DIR         := src
INC_DIR         := include
TEST_DIR        := tests

BUILD_DIR       := build
OBJ_DIR         := $(BUILD_DIR)/obj
TEST_BUILD_DIR  := $(BUILD_DIR)/tests

################################################################################
#                                SOURCE FILES                                  #
################################################################################

SRCS := $(shell find $(SRC_DIR) -type f -name "*.cpp")

OBJS := $(patsubst $(SRC_DIR)/%.cpp,\
	$(OBJ_DIR)/%.o,\
	$(SRCS))

DEPS := $(OBJS:.o=.d)

################################################################################
#                                  DOCKER                                      #
################################################################################

DOCKER_COMPOSE := docker compose
DOCKER_SERVICE := libftpp-dev

docker-build:
	@printf "$(BLUE)[DOCKER]$(RESET) Building image\n"
	@$(DOCKER_COMPOSE) build

docker-shell:
	@printf "$(GREEN)[DOCKER]$(RESET) Opening Debian 13 shell\n"
	@$(DOCKER_COMPOSE) run --rm $(DOCKER_SERVICE)

docker-up:
	@printf "$(GREEN)[DOCKER]$(RESET) Starting container\n"
	@$(DOCKER_COMPOSE) run --rm $(DOCKER_SERVICE)

docker-clean:
	@printf "$(RED)[DOCKER]$(RESET) Removing containers\n"
	@$(DOCKER_COMPOSE) down --remove-orphans

docker-test:
	@printf "$(YELLOW)[DOCKER]$(RESET) Running tests\n"
	@$(DOCKER_COMPOSE) run --rm $(DOCKER_SERVICE) make test

################################################################################
#                                 TEST FILES                                   #
################################################################################

TEST_SRCS := $(shell find $(TEST_DIR) -type f -name "*.cpp")

TEST_BIN := $(TEST_BUILD_DIR)/run_tests

################################################################################
#                                   COLORS                                     #
################################################################################

GREEN   = \033[0;32m
BLUE    = \033[0;34m
YELLOW  = \033[0;33m
RED     = \033[0;31m
RESET   = \033[0m

################################################################################
#                              DEFAULT TARGET                                  #
################################################################################

all: $(LIBRARY)

################################################################################
#                                LIBRARY                                       #
################################################################################

$(LIBRARY): $(OBJS)
	@mkdir -p $(LIB_DIR)
	@printf "$(BLUE)[AR]$(RESET) %s\n" "$@"
	@$(AR) $(ARFLAGS) $@ $^

################################################################################
#                             OBJECT COMPILATION                               #
################################################################################

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@printf "$(GREEN)[CXX]$(RESET) %s\n" "$<"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -c $< -o $@

################################################################################
#                               TEST BUILD                                     #
################################################################################

tests: $(TEST_BIN)

$(TEST_BIN): $(TEST_SRCS) $(LIBRARY)
	@mkdir -p $(dir $@)
	@printf "$(YELLOW)[TEST]$(RESET) building tests\n"
	@$(CXX) $(CPPFLAGS) $(CXXFLAGS) \
		$(TEST_SRCS) \
		-L$(LIB_DIR) -lftpp \
		-o $@

################################################################################
#                               RUN TESTS                                      #
################################################################################

test: tests
	@echo
	@printf "$(BLUE)===============================$(RESET)\n"
	@printf "$(BLUE)Running unit tests$(RESET)\n"
	@printf "$(BLUE)===============================$(RESET)\n"
	@$(TEST_BIN)

################################################################################
#                             BUILD MODES                                      #
################################################################################

debug:
	@$(MAKE) MODE=debug

release:
	@$(MAKE) MODE=release

################################################################################
#                                CLEAN                                         #
################################################################################

clean:
	@printf "$(RED)[RM]$(RESET) build/\n"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@printf "$(RED)[RM]$(RESET) lib/\n"
	@rm -rf $(LIB_DIR)

re: fclean all

################################################################################
#                                 INFORMATIONS                                 #
################################################################################

info:
	@echo ""
	@echo "Library : $(LIBRARY)"
	@echo ""
	@echo "Sources:"
	@printf "  %s\n" $(SRCS)
	@echo ""
	@echo "Tests:"
	@printf "  %s\n" $(TEST_SRCS)
	@echo ""

################################################################################
#                                PHONY                                         #
################################################################################

.PHONY: \
	all \
	tests \
	test \
	debug \
	release \
	info \
	clean \
	fclean \
	re \
	docker-build \
	docker-shell \
	docker-up \
	docker-clean \
	docker-test

-include $(DEPS)
