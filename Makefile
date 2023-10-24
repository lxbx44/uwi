SRC_DIR = src
BUILD_DIR = build
CXX = g++ 
INSTALL_DIR = /usr/local/bin

SRCS = main.cpp tokenization.cpp remove.cpp toAsm.cpp tokenViewer.cpp parser.cpp
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))

CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lstdc++

all: uwic

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

uwic: $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $(BUILD_DIR)/$@ $(LDFLAGS)

install: uwic
	sudo cp $(BUILD_DIR)/uwic $(INSTALL_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean install
