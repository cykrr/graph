INCLUDE=-Iinclude
OBJS=glad.o camera.o window_manager.o \
	 shaders.o program.o color.o \
	 plane.o element.o
LINKS=-lm -ldl -lGL -lglfw 
new: src/main.cpp $(OBJS) 
	g++ src/main.cpp $(LINKS) $(INCLUDE) $(OBJS) -o new
glad.o: src/glad.c
	g++ -c src/glad.c $(INCLUDE)
camera.o: src/camera.cpp
	g++ -c src/camera.cpp $(INCLUDE)
window_manager.o: src/window_manager.cpp
	g++ -c src/window_manager.cpp $(INCLUDE)
shaders.o: src/shaders.cpp
	g++ -c src/shaders.cpp $(INCLUDE)
program.o: src/program.cpp
	g++ -c src/program.cpp $(INCLUDE)
color.o: src/color.cpp
	g++ -c src/color.cpp $(INCLUDE)
plane.o: src/plane.cpp
	g++ -c src/plane.cpp $(INCLUDE)
element.o: src/element.cpp
	g++ -c src/element.cpp $(INCLUDE)
windows: $(OBJS)
	 g++ src/main.cpp $(OBJS) $(INCLUDE) -Llinks -lglfw3dll -o new -g

clean:
	rm *.o new

