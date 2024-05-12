
test: build
	cd build/ && meson test

build:
	meson setup --reconfigure build
