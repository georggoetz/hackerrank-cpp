GTEST_DIR = ${GTEST_PATH}
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test
INC_DIR = include
LIB_DIR = lib
BIN_DIR = bin

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# House-keeping build targets.

.PHONY: clean dir check

all: dir \
		 $(BIN_DIR)/sample_check \
		 $(BIN_DIR)/cycle_detection_check \
		 $(BIN_DIR)/is_this_a_bst_check \
		 $(BIN_DIR)/huffman_decoding_check

check:
	$(BIN_DIR)/sample_check
	$(BIN_DIR)/cycle_detection_check
	$(BIN_DIR)/is_this_a_bst_check
	$(BIN_DIR)/huffman_decoding_check

dir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(LIB_DIR)
	mkdir -p $(BIN_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(BIN_DIR)

# Builds gtest.a and gtest_main.a.

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

# For simplicity and to avoid depending on Google Test's
# implementation details, the dependencies specified below are
# conservative and not optimized.  This is fine as Google Test
# compiles fast and for ordinary users its source rarely changes.
$(OBJ_DIR)/gtest-all.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest-all.cc -o $@

$(OBJ_DIR)/gtest_main.o : $(GTEST_SRCS_)
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
	$(GTEST_DIR)/src/gtest_main.cc -o $@

$(LIB_DIR)/gtest.a : $(OBJ_DIR)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(LIB_DIR)/gtest_main.a : $(OBJ_DIR)/gtest-all.o $(OBJ_DIR)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR)/include/gtest \
	              $(GTEST_DIR)/include/gtest/internal

# Builds a sample test.  A test should link with either gtest.a or
# gtest_main.a, depending on whether it defines its own main()
# function.

$(OBJ_DIR)/sample.o: $(SRC_DIR)/sample.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/sample_test.o: $(TEST_DIR)/sample_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(BIN_DIR)/sample_check: $(OBJ_DIR)/sample.o $(OBJ_DIR)/sample_test.o $(LIB_DIR)/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

# Builds cyle detection

$(OBJ_DIR)/cycle_detection.o: $(SRC_DIR)/cycle_detection.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/cycle_detection_test.o: $(TEST_DIR)/cycle_detection_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(BIN_DIR)/cycle_detection_check: $(OBJ_DIR)/cycle_detection.o $(OBJ_DIR)/cycle_detection_test.o $(LIB_DIR)/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

# Builds is this a binary search tree

$(OBJ_DIR)/is_this_a_bst.o: $(SRC_DIR)/is_this_a_bst.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/is_this_a_bst_test.o: $(TEST_DIR)/is_this_a_bst_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(BIN_DIR)/is_this_a_bst_check: $(OBJ_DIR)/is_this_a_bst.o $(OBJ_DIR)/is_this_a_bst_test.o $(LIB_DIR)/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@

# Builds huffman decoding

$(OBJ_DIR)/huffman_decoding.o: $(SRC_DIR)/huffman_decoding.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(OBJ_DIR)/huffman_decoding_test.o: $(TEST_DIR)/huffman_decoding_test.cc $(GTEST_HEADERS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -I $(INC_DIR) -c -o $@ $<

$(BIN_DIR)/huffman_decoding_check: $(OBJ_DIR)/huffman_decoding.o $(OBJ_DIR)/huffman_decoding_test.o $(LIB_DIR)/gtest_main.a
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -lpthread $^ -o $@
