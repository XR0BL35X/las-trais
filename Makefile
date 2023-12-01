CXX = g++ 
CXXFLAGS = -IC:\msys64\mingw64\include\SDL2 -LC:\msys64\mingw64\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2

all: bin/tutorial0 bin/tutorial1

bin/tutorial0 : Source Files/Bullet.cpp
	$(CXX) $< $(CXXFLAGS) -o $@

bin/tutorial1 : src/02_getting_an_image_on_the_screen.cpp
	$(CXX) $< $(CXXFLAGS) -o $@ 

bin/tutorial2 : src/03_event_driven_programming.cpp
	$(CXX) $< $(CXXFLAGS) -o $@ 

bin/tutorial3 : src/04_key_presses.cpp
	$(CXX) $< $(CXXFLAGS) -o $@ 	

bin/tutorial4 : src/05_optimized_surface_loading_and_soft_stretching.cpp
	$(CXX) $< $(CXXFLAGS) -o $@ 	

runT0: bin/tutorial0	
	./$<

runT1: bin/tutorial1
	./$<

runT2: bin/tutorial2
	./$<

runT3: bin/tutorial3
	./$<	

runT4: bin/tutorial4
	./$<	