
unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

player += files('TestPlayer.c')

player01 = executable('player01',
  sources: [
    player,
    unity_gen_runner.process('TestPlayer.c')
  ],
  include_directories: [ inc ],
  dependencies: [ unity_dependency ],
)

test('player-01', player01)
