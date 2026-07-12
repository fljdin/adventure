
unity_sp = subproject('unity')
unity_gen_runner = unity_sp.get_variable('gen_test_runner')

testing = [
  { 'name': 'item', 'file': 'test_item.c' },
  { 'name': 'entity', 'file': 'test_player.c' },
  { 'name': 'inventory', 'file': 'test_inventory.c' },
  { 'name': 'dungeon', 'file': 'test_dungeon.c' },
  { 'name': 'dice', 'file': 'test_dice.c' },
  { 'name': 'combat', 'file': 'test_combat.c' },
  { 'name': 'monster', 'file': 'test_monster.c' },
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
