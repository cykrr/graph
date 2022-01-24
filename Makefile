CXX:=g++
INCLUDE=-Iinclude
OBJS=glad.o camera.o window_manager.o \
	 shaders.o program.o color.o stbi.o \
	 plane.o element.o
LINKS=-lm -ldl -lGL -lglfw 
new: src/main.cpp $(OBJS) 
	$(CXX) src/main.cpp $(LINKS) $(INCLUDE) $(OBJS) -o new
glad.o: src/glad.c
	$(CXX) -c src/glad.c $(INCLUDE)
camera.o: src/camera.cpp 
	$(CXX) -c src/camera.cpp $(INCLUDE) 
window_manager.o: src/window_manager.cpp
	$(CXX) -c src/window_manager.cpp $(INCLUDE)
shaders.o: src/shaders.cpp
	$(CXX) -c src/shaders.cpp $(INCLUDE)
program.o: src/program.cpp
	$(CXX) -c src/program.cpp $(INCLUDE)
color.o: src/color.cpp
	$(CXX) -c src/color.cpp $(INCLUDE)
plane.o: src/plane.cpp
	$(CXX) -c src/plane.cpp $(INCLUDE)
element.o: src/element.cpp
	$(CXX) -c src/element.cpp $(INCLUDE)

stbi.o: src/stbi.cpp
	$(CXX) -c src/stbi.cpp $(INCLUDE)

windows: $(OBJS)
	 $(CXX) src/main.cpp $(OBJS) $(INCLUDE)  -o new -g -Lmingw_links \
		 -lglfw3 -lopengl32 -lgdi32 \
		 -static -static-libstdc++ -static-libgcc 	

clean:
	rm *.o new

