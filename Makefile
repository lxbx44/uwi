SRC_DIR = src
BUILD_DIR = build

test:
	gcc $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/uwic -lstdc++
	./$(BUILD_DIR)/uwic test.uwi
	rm $(BUILD_DIR)/uwic
