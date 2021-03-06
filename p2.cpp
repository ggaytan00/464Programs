//FOR THE USE IN CSCE464 sdalf
//Copyright © 2016 by George Steven Gaytan
//All Rights Reserved
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int count = 1;
int xCount = 0;
const int packet_trans = 1000;

void p2();

struct Simulation {
    int X = 3;
    int Xi = -1;
    int Ri = 1;
	bool success;
};

int main(){
	p2();
	// ofstream myfile;
	// myfile.open ("hw5p2.txt");
	// //myfile << p2();
	// myfile.close();
	return 0;

}

void p2(){
	Simulation sim;
	vector<Simulation> simVect;
	while (count <= packet_trans){
		xCount = 0;

		while(xCount < sim.X){
			//Trans 0 to 15
			if(sim.Xi <= 15){
				//cout << sim.Ri << "ri xi" << (sim.Xi +2) << '\n';
				if(sim.Ri == 1 || sim.Ri == 2){
					sim.Xi++;
					sim.success = true;
					simVect.push_back(sim);
					count++;
					xCount++;
	            }
				if(sim.Ri == 3){
					sim.Xi++;
					sim.success = false;
					simVect.push_back(sim);
					count++;

					if(sim.Xi == 16){
						break;
					}

                    sim.Xi++;
                    sim.success = false;
                    simVect.push_back(sim);
                    count++;

					sim.X++;
					xCount = sim.X;
					sim.Ri -= 2;
					break;
				}
				
			}

			if(16 <= sim.Xi && sim.Xi <= 25){
				cout << "asdf";
				//quick check to reinit loop if just exited previous if
				if(xCount == sim.X) { break; }

                if(sim.Ri == 1 || sim.Ri == 2 || sim.Ri == 3){
                    sim.Xi++;
                    sim.success = true;
                    simVect.push_back(sim);
                    count++;
                    xCount++;
                }
                if(sim.Ri == 4){
                    sim.Xi++;
                    sim.success = false;
                    simVect.push_back(sim);
                    count++;
					
                    if(sim.Xi == 26){
                        break;
                    }

                    sim.Xi++;
                    sim.success = false;
                    simVect.push_back(sim);
                    count++;
					
                    sim.X++;
                    xCount = sim.X;
                    sim.Ri -= 2;
                    break;
				}
			
			}

			if(26 <= sim.Xi && sim.Xi <= 30){
				cout << "asdasdfasdff";
				//quick check to reinit loop if just exited previous if
				if(xCount == sim.X) { break; }

				if(sim.Ri == 1 || sim.Ri == 2){
					sim.Xi++;
					sim.success = true;
					simVect.push_back(sim);
					count++;
					xCount++;
	            }
				if(sim.Ri == 3){
					sim.Xi++;
					sim.success = false;
					simVect.push_back(sim);
					count++;

					if(sim.Xi == 31){
						break;
					}

                    sim.Xi++;
                    sim.success = false;
                    simVect.push_back(sim);
                    count++;

					sim.X++;
					xCount = sim.X;
					sim.Ri -= 2;
					break;
				}
				
			}

			if(sim.Xi >= 31){
				cout << '\n' << count << ":" <<  xCount << ":" << sim.Xi << ":"<< sim.Ri << ":" << sim.X << '\n';
				//quick check to reinit loop if just exited previous if
				if(xCount == sim.X) { break; }
				//quick check for last transmission range
				//this exits program upon 1k trans
                if(sim.Xi >= 1000){
                  	break;
                }
				// cout << "c " << count << "\n";
				// cout << "Xi " << sim.Xi << "\n";
				if (sim.Ri > 6) exit(0);

				if(count >= (packet_trans+2)) { break; }

                if(sim.Ri == 1 || sim.Ri == 2 || sim.Ri == 3){
                    sim.Xi++;
                    sim.success = true;
                    simVect.push_back(sim);
                    count++;
                    xCount++;
                }
                if(sim.Ri == 4){
                    sim.Xi++;
                    sim.success = false;
                    simVect.push_back(sim);
                    count++;
					
                    if(sim.Xi >= 1000){
                        break;
                    }

                    sim.Xi++;
                    sim.success = false;
                    simVect.push_back(sim);
                    count++;
					
                    sim.X++;
                    xCount = sim.X;
                    sim.Ri -= 2;
                    break;
				}
			
			}

		}	
		sim.Ri++;
	}

	int successes = 0;
	int failures = 0;

	for(int i = 0; i < packet_trans; i++){
		cout << boolalpha;
		cout << "Packet" << (i+1) << ":" << simVect[i].success << "\n";
		
		if (simVect[i].success) { successes++; }
		if (!simVect[i].success) { failures++; }
	}

	cout << "We saw " << successes << "successful transmissions\n";
	cout << "We saw " << failures << "failed transmissions\n";
}





