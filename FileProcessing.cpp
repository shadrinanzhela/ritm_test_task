#include "FileProcessing.h"

int FileProcessing::InputProcossing(string input, shared_ptr <GraphData>& graph) {
	ifstream in(input);
	if (!in) {
		cerr << "input file didn't open\n";
		return 1;
	}
	int NV, NE;
	in >> NV >> NE;
	graph->ChangeNV(NE);
	graph->ChangeNE(NE);

	string line;
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(in, line);

	for (int i = 0; i < NV; i++) graph->AddVertex(); //инициализируем вершины

	//считываем ребра
	int u, v;
	for (int i = 0; i < NE; ++i) {
		in >> u >> v;
		if (!((-1 < u - 1) && (u - 1 < NV + 1) && (-1 < v - 1) && (v - 1 < NV + 1))) {
			cerr << "add edge" << u << " " << v << "error/n";
			return 1;
		}
		shared_ptr<EdgeData> edge = make_shared<EdgeData>(u - 1, v - 1);
		graph->AddEdge(edge);
		((graph->ReadVertex())[v - 1]->ReadInEdge()).push_back(edge);

		in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	getline(in, line);

	//считываем правила для вершин
	double value;
	string str;
	int num;
	for (int i = 0; i < NV; i++) {
		if (in >> value) {
			graph->AddRulVertex(i, 1, 0, value, "");
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		in.clear();
		in >> str;
		if (!str.compare("v") || !str.compare("e")) {
			in >> num;
			if (!str.compare("v")) {
				if (!(-1 < num - 1) && !(num - 1 < NV)) {
					cerr << "add vertex rul", i, "error\n";
					return 1;
				}
			}
			else {
				if (!(-1 < num - 1) && !(num - 1 < NE)) {
					cerr << "add vertex rul", i, "error\n";
					return 1;
				}
			}
			graph->AddRulVertex(i, 2, num - 1, 0, str);
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!str.compare("min")) {
			graph->AddRulVertex(i, 3, 0, 0, "");
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;;
		}
		cerr << "add vertex rul", i + 1, "error/n";
		return 1;
	}

	//считываем правила для ребер
	for (int i = 0; i < NE; i++) {
		if (in >> v) {
			graph->AddRulEdge(i, 1, 0, v, "");
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		in.clear();
		in >> str;
		if (!str.compare("v") || !str.compare("e")) {
			in >> num;
			if (!str.compare("v")) {
				if (!(-1 < num - 1) && !(num - 1 < NV)) {
					cerr << "add vertex rul", i, "error\n";
					return 1;
				}
			}
			else {
				if (!(-1 < num - 1) && !(num - 1 < NE)) {
					cerr << "add vertex rul", i, "error\n";
					return 1;
				}
			}
			graph->AddRulEdge(i, 2, num - 1, 0, str);
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!str.compare("*")) {
			graph->AddRulEdge(i, 3, 0, 0, "");
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		cerr << "add edge rul", i + 1, "error/n";
		return 1;
	}

	return 0;
}

int FileProcessing::OutputProcessing(string output, shared_ptr <GraphData>& graph) {
	ofstream out(output);
	if (!out) {
		cerr << "output file didn't open\n";
		return 1;
	}
	for (int i = 0; i < graph->ReadNV(); i++) {
		out << std::fixed << graph->ReadVertex()[i]->ReadAttr() << "\n";
	}
	for (int i = 0; i < graph->ReadNE(); i++) {
		out << std::fixed << graph->ReadEdge()[i]->ReadAttr() << "\n";
	}
	return 0;
}