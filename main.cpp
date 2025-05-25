#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <memory>
#include "FileProcessing.h"
#include "GraphData.h"

using namespace std;


int main(/*int argc, char* argv[]*/) {
	int argc = 3;
	string str[3];
	str[1] = "input.txt";
	str[2] = "output.txt";

	if (argc < 3) {
		cerr << "input error\n";
		return 1;
	}

	shared_ptr <GraphData> graph = make_shared<GraphData>();

	if (FileProcessing::InputProcossing(/*argv[1]*/ str[1], graph)) return 1;

	if (graph->ComputeGraph()) return 1;

	if (FileProcessing::OutputProcessing(/*argv[2]*/ str[2], graph)) return 1;

	return 0;
}