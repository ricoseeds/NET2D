Mac installation

brew install glfw3
brew install glew

XCode Project setup 

1. Select project
1.1 goto Build Settings > Add "usr/local/include" to header_search_path

2. Goto Build Settings 
2.1 Add Opengl.framework
2.2 AddOther > (CMD + SHIFT + G) > /usr/local/Cellar/glfw/3.X.X/libglfwX.X.dylib
2.3 AddOther > (CMD + SHIFT + G) > /usr/local/Cellar/glew/X.X.X/libglewX.X.dylib

And all good to go!
