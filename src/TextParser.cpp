//============================================================================
// Name        : TextParser.cpp
// Author      : Papikas Ioannis
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void loadData(const char *fname);

int main() {
	loadData("docword.kos.txt");
	return 0;
}

void loadData(const char *states, const char *data)
{
	int D, W, NNZ;
	FILE *f;
	f = fopen(states, "r");
	if (f)
    {
		// Scan data
		fscanf(f, "%d\n%d\n%d\n", &D, &W, &NNZ);
		int lastDocID = 1;
		int lastWordID = 0;

		int docID, wordID, count;
		printf("[");
		do
		{
			// Get File Data
			fscanf(f, "%d %d %d\n", &docID, &wordID, &count);

			// Chagne doc line
			if (docID > lastDocID)
			{
				for (int i=lastWordID; i<W; i++)
					printf("0 ");

				printf(";\n");
				lastDocID = docID;
				lastWordID = 0;
			}

			// Print counts
			for (int i=lastWordID; i<wordID; i++)
				printf("0 ");

			// Print count value
			printf("%d ", count);
			lastWordID = wordID+1;
		} while (lastDocID <= 50);
		printf("];");
		fclose(f);
    }
}

