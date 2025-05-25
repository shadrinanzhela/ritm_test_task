#include"GraphData.h"

void GraphData::AddRulVertex(int num, int numRul, int i, double d, string str) {
	shared_ptr <VertexData> vertex = Vertex[num];
	

	vertex->ChangeNumRul(numRul);
	switch (numRul) {
	case 1:
		vertex->ChangeVal(d);
		break;
	case 2:
		if (!str.compare("v")) vertex->ChangeFromVertex(1);
		else vertex->ChangeFromVertex(0);
		vertex->ChangeNum(i);
		break;
	}
}


void GraphData::AddRulEdge(int numEdge, int numRul, int i, double d, string str) {
	shared_ptr <EdgeData> edge = Edge[numEdge];
	edge->ChangeNumRul(numRul);
	switch (numRul) {
	case(1):
		edge->ChangeVal(i);
		break;
	case(2):
		if (!str.compare("v")) edge->ChangeFromVertex(1);
		else edge->ChangeFromVertex(0);
		edge->ChangeNum(i);
		break;
	}
}

double GraphData::Mod(double i) { return round(i * 1000.0) / 1000.0; }

int GraphData::ComputeEdge(shared_ptr<EdgeData> edge) {
	if (!isnan(edge->ReadAttr())) return 0;
	//проверка на цикл
	if (edge->ReadVisited()) {
		cerr << "calculation error. Cycle\n";
		return 1;
	}

	switch (edge->ReadNumRul()) {
	case(1):

		edge->ChangeAttr(Mod(edge->ReadVal()));
		edge->ChangeVisited(1);
		break;

	case(2):
		if (edge->ReadFromVertex()) {
			if (ComputeVertex(Vertex[edge->ReadNum()])) return 1;
			edge->ChangeAttr(Mod(Vertex[edge->ReadNum()]->ReadAttr()));
		}
		else {
			if (ComputeEdge(Edge[edge->ReadNum()])) return 1;
			edge->ChangeAttr(Mod(Edge[edge->ReadNum()]->ReadAttr()));
		}
		edge->ChangeVisited(1);
		break;

	case(3):
		if (ComputeVertex(Vertex[edge->ReadIn()]))return 1;
		double answ = Vertex[edge->ReadIn()]->ReadAttr();
		int counEdge = Vertex[edge->ReadIn()]->ReadInEdge().size();
		if (counEdge == 0) {
			cerr << "calculation error. Vertex havn't incoming edges\n";
			return 1;
		}

		for (int i = 0; i < counEdge; i++) {
			if (ComputeEdge(Vertex[edge->ReadIn()]->ReadInEdge()[i]))
			{
				cerr << "calculation error. Cycle\n";
				return 1;
			}
			answ *= Vertex[edge->ReadIn()]->ReadInEdge()[i]->ReadAttr();
			answ = Mod(answ);
		}
		edge->ChangeAttr(answ);
		edge->ChangeVisited(1);
		break;
	}


	return 0;
}


int GraphData::ComputeVertex(shared_ptr <VertexData> vertex) {
	if (!isnan(vertex->ReadAttr())) return 0;
	//проверка на цикл
	if (vertex->ReadVisited()) {
		cerr << "calculation error. Cycle\n";
		return 1;
	}

	switch (vertex->ReadNumRul()) {
	case(1):
		vertex->ChangeAttr(Mod(vertex->ReadVal()));
		vertex->ChangeVisited(1);
		break;

	case(2):
		if (vertex->ReadFromVertex()) {
			if (ComputeVertex(Vertex[vertex->ReadNum()])) return 1;
			vertex->ChangeAttr(Mod(Vertex[vertex->ReadNum()]->ReadAttr()));
		}
		else {
			if (ComputeEdge(Edge[vertex->ReadNum()])) return 1;
			vertex->ChangeAttr(Mod(Edge[vertex->ReadNum()]->ReadAttr()));
		}
		vertex->ChangeVisited(1);
		break;

	case(3):
		int counEdge = vertex->ReadInEdge().size();
		if (counEdge == 0) {
			cerr << "calculation error. Vertex havn't incoming edges\n";
			return 1;
		}

		if (ComputeEdge(vertex->ReadInEdge()[0]))
		{
			cerr << "calculation error. Cycle\n";
			return 1;
		}
		double min = vertex->ReadInEdge()[0]->ReadAttr();
		for (int i = 1; i < counEdge; i++) {
			if (ComputeEdge(vertex->ReadInEdge()[i]))
			{
				cerr << "calculation error. Cycle\n";
				return 1;
			}

			if (min > vertex->ReadInEdge()[i]->ReadAttr()) min = vertex->ReadInEdge()[i]->ReadAttr();
		}

		vertex->ChangeAttr(min);
		vertex->ChangeVisited(1);
		break;
	}
	return 0;
}


int GraphData::ComputeGraph() {
	//вычисляем значения вершин
	for (int i = 0; i < NV; i++) {
		if (ComputeVertex(Vertex[i])) return 1;
	}

	//вычисляем значения ребер
	for (int i = 0; i < NE; i++) {
		if (ComputeEdge(Edge[i])) return 1;
	}
	return 0;
}