.PHONY: test build

build:
	meson setup --reconfigure build
	cd build/ && meson compile

test: build
	cd build/ && meson test
