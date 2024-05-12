project('adventure', 'c',
  license: 'The Unlicense',
  meson_version: '>= 1.0.0',
  default_options: [
    'c_std=c99',
    'warning_level=3',
  ]
)

unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

player = files([
  'src' / 'Player.c',
  'test' / 'TestPlayer.c',
])

inc = include_directories('src')

player01 = executable('player01',
  sources: [
    player,
    unity_gen_runner.process('test' / 'TestPlayer.c')
  ],
  include_directories: [ inc ],
  dependencies: [ unity_dependency ],
)

test('player-01', player01)
