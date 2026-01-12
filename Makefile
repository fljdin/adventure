.PHONY: build

build:
	meson setup --reconfigure build
	meson compile -C build

tests:
	meson test -C build -v

clean:
	rm -rf build .cache subprojects/*/
