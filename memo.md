【備忘録/確認事項】

■ 実行するとSegfaultになるときと正常に動くときがある。
	なぜ？フリー？の問題？ Or Mallocミス？ ---> FIXED


■ マップもうちょっとちゃんとやる。
- when 'P' is not found -> error and quit
- when 'E' is not found -> error and quit
- when 'C' is not found -> error and quit


■ エラーケースのハンドル
・プレーヤーの数：1人に限定する
・Exitの数：１に限定する
・マップ Malloc fail
・イメージファイル呼び込み失敗
・マップファイルの呼び込み失敗
・The player goes outside the window/map. 

・Free... i want to be free....

■ スタートとエンディングの絵？

■ ゲームルール
・全部集めないと終了できなくする


///////////////////////////////////////////
-- window
• The management of your window must remain smooth: changing to another window, minimizing, etc.
• You will use a 2D view (top-down or profile).

-- map
• The map will be constructed with 3 components walls, collectibles, and free space.
Your program must take as a first argument a map description file with the .ber
extension.
◦ The map must be composed of only 5 possible characters: 
0 for an empty space,
1 for a wall,
C for a collectible,
E for map exit,
P for the player’s starting position.

◦ The map must be closed/surrounded by walls, if not the program must return an error.
◦ Map must have at least one exit, one collectible, and one starting position.
◦ You don’t need to check if there’s a valid path in the map.
◦ The map must be rectangular.
◦ You must be able to parse any kind of map, as long as it respects the rules of the map.


malloc map
parse map 
	--> check composition (0,1,C,E,P) 
	--> check how many
	--> check if map is surrounded by walls
	--> check if map is rectangular

know the locations of each composition
	--> give coordinates

draw map
	--> apply each image according to the component		()

-- key input

-- movement
• At every move the current number of movements must be displayed in the shell.
	-> displaying the count on the window is a bonus.
• The player must be able to move: up, down, left, right.
• player cannot move into walls.


-- sprites


-- textures


-- get fissshhhhhh (collectible)

how to tell all collectibles are collected
count down until zero ("to_be_collected")


idea 1):linked list?
Cの数だけNodesをつくって、同じ座標に重なったら一つずつ消していく


Collision
これがおきたら自動的にCollectibleの絵が消えてほしい。ぽん。


-- exit
- esc key
- red cross button
- when fish is caught?



-----------------

• The game doesn’t need to be real-time.???



