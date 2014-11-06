cubix-cpp
=========

A 2D game written in C++ using OpenGL 3.3.

For now this is going to mainly serve as a platform for advancing my C++ knowledge; with a little expirementation thrown in.

To build you are going to need CMake. I've been thinking about trying scons, so i may offer than as an option later on as well.

Dependancies
------------
* SDL2
* GLM
* GLEW
* CMake
* A C++ compiler :P
*

Project Thoughts/Plans
----------------------
(Just wrote down whatever came to mind that seemed interesting)
* Look into alternative build systems.
  * Currently CMake is an extremely good option, more features, faster?
  * Also look into using scons, it also looks like a good alternative, uses python, not as many features, more exact.
* I would also like to look into some lighter weight alteratives to GLEW in the future.
  * Could fork and update gl3w.
  * Work on that planned opengl binding for python, and also let it export stuff for C/C++
  * GLXW looks pretty good supports :gl wgl glx gles2 egl khr.
* SDL2 for windows initially.
* use glm for math library.
* OpenGL 3.3 based rendering
* freetype2 based font rendering
  * Will need a texture atlas
* For a UI system I really need to study up on various "Modern" UI systems.
	* Reach into the horidness of JavaScript frameworks for insperation.
	* look at Qt 5 as an example.
	* WPF (Windows Presentation Foundation) API's my be good to study.
	* I really need to iterate on this and figure out what works the best.
	  *  Mainly cause i haven't before.
		* To do this right, i need to have a well abstracted 2D rendering API so i can move quickly.
* I have been reading through Game Programming Patterns, I would like to apply much of the content presented there to this project as well.

