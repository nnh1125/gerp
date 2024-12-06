###
### Makefile for Gerp Project
###
### Author:  YOUR NAME HERE

## 
## Build up your Makefile in a similar manner as for Zap. Feel free 
## to use that Makefile to guide you! Note, you do NOT need rules for
## FSTree.o and DirNode.o as those (pre-compiled) object files are 
## provided to you.
## 
## At the end, you can delete this comment!
## 
CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow -O2
LDFLAGS  = -g3


# processing: main.o processing.o FSTree.o DirNode.o
# 	${CXX} ${LDFLAGS} -o processing $^

# main.o: main.cpp processing.h DirNode.h FSTree.h
# 	${CXX} ${CXXFLAGS} -c main.cpp

main.o: main.cpp Dictionary.h
	${CXX} ${CXXFLAGS} -c main.cpp

map: main.o Dictionary.o
	${CXX} ${LDFLAGS} -o map $^

processing.o: processing.h processing.cpp DirNode.h FSTree.h
	${CXX} ${CXXFLAGS} -c processing.cpp

Dictionary.o: Dictionary.h Dictionary.cpp SWord.o
	${CXX} ${CXXFLAGS} -c Dictionary.cpp

SWord.o: SWord.h SWord.cpp
	${CXX} ${CXXFLAGS} -c SWord.cpp

# The below rule will be used by unit_test.
unit_test: unit_test_driver.o Dictionary.o
	$(CXX) $(CXXFLAGS) $^

##
## Here is a special rule that removes all .o files besides the provided ones 
## (DirNode.o and FSTree.o), all temporary files (ending with ~), and 
## a.out produced by running unit_test. First, we find all .o files 
## that are not provided files, then we run rm -f on each found file 
## using the -exec find flag. Second, we delete the temporary files
## and a.out. @ is used to suppress stdout.
## 
## You do not need to modify or further comment this rule!
##
clean:
	@find . -type f \( \
		-name '*.o' ! -name 'FSTree.o' ! -name 'DirNode.o' \
		\) -exec rm -f {} \;
	@rm -f *~ a.out

