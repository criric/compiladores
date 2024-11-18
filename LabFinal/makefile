CXX = g++
CXXFLAGS = -std=c++17

FLEX = flex++
FLEX_SRC = lexer.l
FLEX_OUT = lex.yy.cc

SRC = $(wildcard *.cpp)
TARGET = tradutor

all: $(TARGET)

$(TARGET): $(FLEX_OUT) $(SRC)
	$(CXX) $(CXXFLAGS) $(FLEX_OUT) $(SRC) -o $(TARGET)

$(FLEX_OUT): $(FLEX_SRC)
	$(FLEX) $(FLEX_SRC)

clean:
	rm -f $(FLEX_OUT) $(TARGET)

run: $(TARGET)
	./$(TARGET)
