
unity_subproject = subproject('unity')
unity_dependency = unity_subproject.get_variable('unity_dep')
unity_gen_runner = unity_subproject.get_variable('gen_test_runner')

testing = [
  { 'name': 'player', 'source': player, 'file': 'TestPlayer.c' },
  { 'name': 'map', 'source': map, 'file': 'TestMap.c' },
  { 'name': 'game', 'source': game, 'file': 'TestGame.c' },
]

foreach test : testing
  test(test['name'], executable(test['name'],
    sources: [
      test['source'] + files(test['file']),
      unity_gen_runner.process(test['file'])
    ],
    include_directories: [ inc ],
    dependencies: [ unity_dependency ],
  ))
endforeach
