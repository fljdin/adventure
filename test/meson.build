
unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

player += files('TestPlayer.c')
test('player', executable('player',
  sources: [
    player,
    unity_gen_runner.process('TestPlayer.c')
  ],
  include_directories: [ inc ],
  dependencies: [ unity_dependency ],
))

map += files('TestMap.c')
test('map', executable('map',
  sources: [
    map,
    unity_gen_runner.process('TestMap.c')
  ],
  include_directories: [ inc ],
  dependencies: [ unity_dependency ],
))
