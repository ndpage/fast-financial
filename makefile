include env.settings

CMAKE ?= cmake
CMAKE_ARGS ?=

all:
	$(CMAKE) -S . -B $(BUILD_DIR) $(CMAKE_ARGS)
	$(CMAKE) --build $(BUILD_DIR)

clean:
	$(CMAKE) -E remove_directory $(BUILD_DIR)

.PHONY: all clean
