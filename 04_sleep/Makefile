CXX = g++

LIB_DIR = ../lib
# =====================================================================================================================




# ==== kato source file ===============================================================================================
KATO_HEADERS = $(LIB_DIR)/kato/function.hpp $(LIB_DIR)/kato/log.hpp
KATO_CXXFLAGS = -I$(LIB_DIR)
# ==== kato source file ===============================================================================================




# ==== test source files ==============================================================================================
TEST_EXE = test_sleep
TEST_SOURCES = main.cpp
TEST_OBJS = $(addprefix ., $(addsuffix .o, $(basename $(notdir $(TEST_SOURCES)))))
# ==== test source files ==============================================================================================




# ==== gcc flags ======================================================================================================
CXXFLAGS = -Wall -Wextra -Wunused -Wformat -O3 -pthread
CXXFLAGS += $(KATO_CXXFLAGS)

LIBS = -lpthread

CXXFLAGS_STD = $(CXXFLAGS) -std=c++20
# ==== gcc flags ======================================================================================================




# ==== build rules ====================================================================================================
.%.o: %.cpp
	$(CXX) $(CXXFLAGS_STD) -c -o $@ $<

all: $(TEST_EXE)
	@echo Build complete

$(TEST_EXE): $(TEST_OBJS) $(KATO_HEADERS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean_test:
	rm -f $(TEST_EXE) $(TEST_OBJS)

clean: clean_test
# ==== build rules ====================================================================================================
