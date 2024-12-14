CXX = g++
CXXFLAGS = -Wall --std=c++17


comp_test_creature: test_creature.cpp creature.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_creature.cpp creature.cpp catch_amalgamated.cpp -o test_creature.o

test_creature: comp_test_creature
	./test_creature.o

comp_test_bat: test_bat.cpp bat.cpp creature.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_bat.cpp bat.cpp creature.cpp catch_amalgamated.cpp -o test_bat.o

test_bat: comp_test_bat
	./test_bat.o

comp_test_human: test_human.cpp human.cpp creature.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_human.cpp human.cpp creature.cpp catch_amalgamated.cpp -o test_human.o

test_human: comp_test_human
	./test_human.o

comp_test_vampire: test_vampire.cpp vampire.cpp creature.cpp bat.cpp human.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_vampire.cpp vampire.cpp creature.cpp bat.cpp human.cpp catch_amalgamated.cpp -o test_vampire.o

test_vampire: comp_test_vampire
	./test_vampire.o

comp_test_team: test_team.cpp team.cpp creature.cpp bat.cpp human.cpp vampire.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_team.cpp team.cpp creature.cpp bat.cpp human.cpp vampire.cpp catch_amalgamated.cpp -o test_team.o

test_team: comp_test_team
	./test_team.o

comp_test_simulation: test_simulation.cpp simulation.cpp team.cpp creature.cpp bat.cpp human.cpp vampire.cpp catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) test_simulation.cpp simulation.cpp team.cpp creature.cpp bat.cpp human.cpp vampire.cpp catch_amalgamated.cpp -o test_simulation.o

test_simulation: comp_test_simulation
	./test_simulation.o

clean:
	rm -f main *.o