tester: fsm_tester.cpp fsm_skeleton.cpp
		g++ -o tester fsm_tester.cpp fsm_skeleton.cpp

clean:
		rm tester
