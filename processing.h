#ifndef __PROCESSING_H
#define __PROCESSING_H

/*
*  processing.h
*  
*  Date: 11/13/2024
*
*  Author: Jenni Lu, Ha Nguyen
*
*  CS15PROJ4 - gerp (phase 1)
*
*  Description:  
*
*/

#include <string>
#include "DirNode.h"
#include "FSTree.h"
#include <iostream>


using namespace std;

string stripNonAlphaNum(string input);
bool is_alphaNum(char c);
void traverseDirectory(string directory);
void recursivelyTraverse(DirNode *node, string address);

#endif 