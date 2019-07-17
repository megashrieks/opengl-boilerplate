# opengl c++ boiler plate

I just started learning OpenGL with GLFW and GLUT and this is just the basic c++ boiler plate code for most of the setting up of openGL, The logical code I plan to handle by extracting it to external files. 

Edit the basic.frag or create a seperate fragment shader file and include it in Application.cpp to do cool fragment shader stuff like in shadertoy.com

  

## Requirements

- [GLUT](https://www.glfw.org/https://www.glfw.org/)

- [GLEW](http://glew.sourceforge.net/)

I do the compilation of the file in linux. So I had to build GLFW and GLEW from the source.
You can see the building of those projects in their respective sites.

clone the GLFW repository and include the path in the CMakeLists.txt and then execute the commands below
```
cd build
cmake ..
make
./my-first-graphics-app
```

If you are running windows just include the necessary files in Visual Studio and statically link the dependencies and you are good to go.


This boiler plate code is mostly 1 file but since it also contains the folders which contains the basic vertex and fragment shaders I have made it into a repository instead of a gist.
The Code is currently being abstracted into higher level for ease of use. The purpose is to have a game engine kind of feeling using it.
Also the code is mostly the basic code taken from GLFW site.
I might make some changes and add some cool stuff later which might provide a better api for drawing and stuff but currently its just some code which will execute your fragment shaders

> Note : the resolution is not passed to the fragment shaders yet but the time is passed as a uniform.
