TARGET = jsonlite

all: $(TARGET)

$(TARGET): main.cpp JsonLite.h
	g++ -g -o $@ $<

.PHONY: clean
clean:
	-rm $(TARGET)

.PHONY: test
test: all
	@./$(TARGET)
