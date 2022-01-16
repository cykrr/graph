INCLUDE=-Iinclude
OBJS=glad.o camera.o window_manager.o shaders.o program.o
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
clean:
	rm *.o new
