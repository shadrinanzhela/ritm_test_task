#include "EdgeData.h"


void EdgeData::ChangeAttr(double i) { attr = i; }
void EdgeData::ChangeNumRul(int i) { numRul = i; }
void EdgeData::ChangeVal(double i) { val = i; }
void EdgeData::ChangeFromVertex(bool i) { fromVertex = i; }
void EdgeData::ChangeNum(int i) { num = i; }
void EdgeData::ChangeVisited(bool i) { visited = i; }
int EdgeData::ReadIn() { return in; }
int EdgeData::ReadOut() { return out; }
double EdgeData::ReadAttr() { return attr; }
int EdgeData::ReadNumRul() { return numRul; }
double EdgeData::ReadVal() { return val; }
bool EdgeData::ReadFromVertex() { return fromVertex; }
int EdgeData::ReadNum() { return num; }
bool EdgeData::ReadVisited() { return visited; }