## Plan for RogueLike

## Includes
	- olcPixelGameEngine

### Classes will need 
	- World
	- TArray
	- Actor
		- Character : extends Actor
			- Player : extends Character
			- Enemy : extends Character
				- Boss: extends Enemy


### World Class _extends public olc::PixelGameEngine_


	**Struct**
		- MapCoordinates {TVector2D coords{x, y}
	**Methods**
		- World::World()
		- World::~World()
		- void SetBarriers(olc::vi2d)
		- olc::vi2d GetMapCoordinates() { return MapCoordinates.coords}
		- olc::vi2d GetBarriers()
		- virtual bool OnUserCreate() override;
		- virtual bool OnUserUpdate(float fElapsedTime) override;

	**Variables**
		- 

### Player Class
	**Struct**
		- PlayerCoordinates {TVector2D coords{x, y}}
	**Methods:**
		- Player::Player()
			- Initialize player coordinates
			- Initialize player sprite
		- Player::~Player()

		- PlayerMovement() 
			- World.Barriers()
		
		- Quit()

### Story
	The dungeons will be underground raves in basements and stuff.  Gang HQ.

## Requirements
	[Mark 40%] Game Functioning to the minimum outlined in the #design guide
		Basic game loop (under the MUST be satisfied section). 20%
		Locked Doors. 5%
		Enemies. 5%
		Weapon Damage Types. 5%
		Notification System. 5%
	[Mark 10%] Pointer Usage and Reference Usage
		We will be looking for appropriate usages of pointers and references. We expect you to use them in meaningful ways such as to not incur unnecessary object copies, etc.
	[Mark 5%] Const Correctness
		Show that you understand the implications of using const and what you are communicating to other developers that might use your codebase through its usage. 
		You can demonstrate this through thoughtful usage of the const keyword, which implies to use what should and should not be considered mutable or 
		if a function is going to affect the object we pass it. Examples of code used in lectures are "known quantities" (FVector2D for example), 
		and copying that code will not contribute to your grade in this section, to earn the points here you must use const correctness thoughtfully with methods you have designed yourself. 
		Comments also help .😎
	[Mark 10%] Application of OOP Concepts
		You will need to demonstrate usage of classes/structs in a way that follows good OOP practise. 
		You must use BOTH structs and classes appropriately in your code to gain full marks. 
		You can use the material from lectures and labs as a basis for determining what good encapsulation might look like. 
		The Templated Array and Templated Vector Class will not contribute to this section.
	[Mark 10%] Template Vector Class
	​​​​​​​	You will need to implement the TVector2D class – you may use the code we showed you in Lectures and Labs as the base for your implementation. 
	You will need to overload the +, == and += operators for the class, as specified in the technical requirements.
	[Mark 10%] Class Inheritance
	​​​​​​​​​​​​​​	Demonstrate your understanding of class inheritance and virtual functions. 
	You should refer to the “Recommendations” section for a suggested class hierarchy for your game objects and some useful virtual functions
	[Mark 15%] Templated Array Class
	​​​​​​​​​​​​​​	Implement the templated array class as specified later in the brief. You must use this to store your Actors, Items, Doors on a per Map basis.

	#design
	You should be able to use the keyboard (arrow keys) to move the player around, 
	you can either move the player around the Map or the Map around the player (with the player character locked to the centre of the screen). 
	You only need to draw one Map at a time, and that Map should be whatever Map the player is currently in. 

	The players position must be stored as a TVector2D (as described later in the document under technical requirements).
	Any and all locations (X ,Y coordinates) must be stored as your TVector2D class. 
	This includes but is not limited to, the player's position, enemy positions, item positions, door positions. 
	You may use olc::vi2d Vectors ONLY when it's an input to a olc:: method (in fact you will have to when you need to draw a sprite), in which case you copy the data out of your TVector2D object, 
	directly into the olc::vi2d object before it gets passed to the olc:: method. This, like our restictions on the standard library, ensures that the code you've written for TVector2D is robust. 
	If in doubt, ask on Discord.

	The world must be rendered using the olcPixelGameEngine as used in Lab 3.
	If you didn't do the Exercise 2 in Lab 3, then now is the time to do it, you will find the basic logic you'll need in the exercise to continue build the basis for your project.
	OnUserCreate from the PixelGameEngine is called at the start of the game, and should setup all your game assets / world

	OnUserUpdate is called every frame and passes you the argument fElapsedTime, this is the amount of time that has elapsed since the LAST frame in seconds, this is where most of your input detection logic and enemy behvaiour logic should called from.
	You're highly encouraged to read the "recommendations" section for hints on how to structure your project.
	The world should consist of rooms linked to each other via doors (or some door like system). Doors should use an appropriate sprite from the tileset.png to draw with.
	Rooms should be able to have at least two doors, ideally more (a dynamic amount).
	Rooms should have distinct visuals. The tileset.png has brick, stone, cobblestone, wood, etc floor textures.
	As a player my goal is to find the final door and use it to escape.
	Display a message on screen congratulating the player for finishing the level
	All graphics are to be rendered using the tileset.png, including all text.
	If you are feeling adventurous you can use your own tileset.png to supply graphics for the game, we only require you to use SOME form of tileset. You'll find lots of great content online!

	You may add any extra game logic you please on top. Some people have added projectile physics in the past! Go Wild!

## Reccomendations
	I highly recommend that you store all players, enemies, items, doors in your own Template Array class and iterate over those lists calling “Draw” on each one when drawing the Map.

	I highly recommend you store position in the Actor class and use that in your derived classes for your “Draw” function.

	Items and doors in your world ... could also be actors 🤔

	PixelGameEngine uses a different Thread when running the OnUserUpdate and OnUserCreate methods, that you override with your monster world, 
	where as your main function runs in it's own thread, and should really only be used to setup and launch MonsterWorld. 
	Any code in those two functions is run on the PixelGameEngine thread, instead of the main thread. Seeding the srand function is done PER Thread. 
	So when you use srand in your main function, that happens on you main Thread BUT we update our enemy positions with the OnUserUpdate method for our world/engine, 
	which runs in the thread created by pixel game engine, which hasn't had it's srand function seeded yet (since its per thread). 
	The solution to this problem is to run srand IN the Thread created by PixelGameEngine. 
	This is very simple to do, we just run the srand function in the OnUserCreate method we've overriden from pixelgameengine, and you should now have random positions for your enemies.


## Extra Resources
**Epic Games Coding Standard**
https://dev.epicgames.com/documentation/en-us/unreal-engine/epic-cplusplus-coding-standard-for-unreal-engine

**olc Pixel Game Engine wiki**
https://github.com/OneLoneCoder/olcPixelGameEngine/wiki/