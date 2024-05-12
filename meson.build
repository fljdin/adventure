project('adventure', 'c',
  license: 'The Unlicense',
  meson_version: '>= 1.0.0',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ]
)

ncurses_dependency = dependency('ncurses')
inc = include_directories('src')

subdir('src')
subdir('test')

executable('adventure',
  sources: sources,
  include_directories: [ inc ],
  dependencies: [ ncurses_dependency ],
)
