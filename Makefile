.PHONY: test build

build:
	meson setup --reconfigure build
	meson compile -C build

test: build
	meson test -C build -v
