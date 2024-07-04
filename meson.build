project('adventure', 'c',
  license: 'The Unlicense',
  version: '0.0.1',
  meson_version: '>= 1.0.0',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ]
)

ncurses_dep = dependency('ncurses')
yaml_sp = subproject('yaml')
inc = include_directories('src')

subdir('src')
subdir('test')

executable('adventure',
  sources: sources,
  include_directories: [ inc ],
  dependencies: [ ncurses_dep, yaml_sp.get_variable('yaml_dep') ],
)
