
unity_sp = subproject('unity')
unity_gen_runner = unity_sp.get_variable('gen_test_runner')

testing = [
  { 'name': 'player', 'file': 'test_player.c' },
  { 'name': 'inventory', 'file': 'test_inventory.c' },
]

foreach test : testing
  test(test['name'], executable(test['name'],
    sources: [
      core + files(test['file']),
      unity_gen_runner.process(test['file'])
    ],
    include_directories: [ inc ],
    dependencies: [
      unity_sp.get_variable('unity_dep')
    ],
  ))
endforeach
