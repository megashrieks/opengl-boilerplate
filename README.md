# opengl c++ boiler plate

I just started learning OpenGL with GLFW and GLUT and this is just the basic c++ boiler plate code for most of the setting up of openGL, The logical code I plan to handle by extracting it to external files. 

Edit the basic.frag or create a seperate fragment shader file and include it in Application.cpp to do cool fragment shader stuff like in shadertoy.com

  

## Requirements

- [GLUT](https://www.glfw.org/https://www.glfw.org/)

- [GLEW](http://glew.sourceforge.net/)

I do the compilation of the file in linux. So I had to build GLFW and GLEW from the source.
You can see the building of those projects in their respective sites.

The compilation command  after you have built it is : 
 `g++ Application.cpp -lGLEW -lglut -lglfw3 -lGL -lX11 -lpthread -ldl`

If you are running windows just include the necessary files in Visual Studio and statically link the dependencies and you are good to go.

currently I'm not using CMake for handling dependencies but I might add it in the future.

This boiler plate code is mostly 1 file but since it also contains the folders which contains the basic vertex and fragment shaders I have made it into a repository instead of a gist.
Also the code is mostly the basic code taken from GLFW site.
I might make some changes and add some cool stuff later which might provide a better api for drawing and stuff but currently its just some code which will execute your fragment shaders

> Note : the resolution and time are not passed to the fragment shader yet so you might have to do this by yourself, but I plan to do this later.
