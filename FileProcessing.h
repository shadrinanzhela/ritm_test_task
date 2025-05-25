#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include "GraphData.h"
#include <memory>

using namespace std;

class FileProcessing {
public:
	static int InputProcossing(string input, shared_ptr <GraphData>& graph);

	static int OutputProcessing(string output, shared_ptr <GraphData>& graph);
};
