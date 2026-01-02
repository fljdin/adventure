
unity_sp = subproject('unity')
unity_gen_runner = unity_sp.get_variable('gen_test_runner')

testing = [
  { 'name': 'player', 'source': player, 'file': 'TestPlayer.c' },
  { 'name': 'map', 'source': map, 'file': 'TestMap.c' },
]

foreach test : testing
  test(test['name'], executable(test['name'],
    sources: [
      test['source'] + files(test['file']),
      unity_gen_runner.process(test['file'])
    ],
    include_directories: [ inc ],
    dependencies: [ 
      unity_sp.get_variable('unity_dep'), 
      yaml_sp.get_variable('yaml_dep') 
    ],
  ))
endforeach
