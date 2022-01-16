INCLUDE=-Iinclude
OBJS=glad.o camera.o
LINKS=-lm -ldl -lGL -lglfw 
new: src/main.cpp $(OBJS) 
	g++ src/main.cpp $(LINKS) $(INCLUDE) $(OBJS) -o new
glad.o: src/glad.c
	g++ -c src/glad.c $(INCLUDE)
camera.o: src/camera.cpp
	g++ -c src/camera.cpp $(INCLUDE)
