PROGRAM_TEST = testShapes

# Compilation command and flags
CXX=g++ -g
CXXVERSION= -std=c++14
CXXFLAGS= $(CXXVERSION)
LINKFLAGS= -lgtest

# Directories
SRC_DIR = src
GTEST_DIR = test
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Tool varialbes
STATIC_ANALYSIS = cppcheck
STYLE_CHECK = cpplint # cpplint.py

# Default goal, for local compilation
.DEFAULT_GOAL := tests

# default rule for compiling .cc to .o
#$@ is the target of the current rule.
#$< is the first dependency of the current rule.
#$ˆ is all of the dependencies of the current rule.
#The % is a Make wildcard,a placeholder for any file name.

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean up all files that should NOT be submitted
#A phony target is one that is not really the name of a file;
#it is just a name for a recipe to be executed when you make an explicit request. 
.PHONY: clean
clean:
	rm -rf *~ $(SRC)/*.o *.o $(GTEST_DIR)/output/*.dat \
	*.gcov *.gcda *.gcno *.orig \
	$(PROJECT) $(COVERAGE_RESULTS) \
	$(GTEST) $(MEMCHECK_RESULTS) $(COVERAGE_DIR)  \
	$(DOXY_DIR)/html obj bin $(PROGRAM_TEST_CLEAN) \
	$(PROGRAM_TEST_BUGS) $(PROGRAM_TEST)

$(PROGRAM_TEST): $(GTEST_DIR) ${SRC_DIR}
		$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
		$(GTEST_DIR)/*.cpp $(SRC_DIR)/*.cpp $(LINKFLAGS)

# To perform unit tests
tests: $(PROGRAM_TEST)
	./$(PROGRAM_TEST)

