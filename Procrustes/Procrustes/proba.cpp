#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

enum State {INIT, READING, END};

static vector<Mat> points;

vector<Mat> readFromStdInput()
{
	string temp;
	vector<Mat> samples;
	
	State state = INIT;
	int i=0, j = 0;
	int** pointArray;
	
	ifstream iFile;
	iFile.open("/home/stevie/Projects/sandbox_subokita/Sandbox/Procrustes/Procrustes/vert.shape");
	
	while (iFile >> temp)
	{
		cout << i;		
		if (temp == "}")
			state = END;

		switch (state)
		{	
			case INIT:
				pointArray = new int*[40];
				for (int k = 0; k < 2; ++k)
					pointArray[k] = new int[2];
				i = 0;
				break;
			case READING:
				pointArray[i][j%2] = atoi(temp.c_str());
				if (j%2 == 1) ++i;
				j++;
				break;
			case END:
				Mat sample(40,2, CV_32SC1, &pointArray);
				samples.push_back(sample);				
				state = INIT;
				for (int k = 0; k <40; k++)
					for (int l = 0; l< 2; l++)
						cout<<pointArray[k][l]<<" ";
				break;
					
		}
		
		if (temp == "{")
		{
			state = READING;
			iFile >> temp;
			iFile >> temp;
		}
		else if (temp == "}")
			state = END;
		
	}
	iFile.close();
}


int main(int argc, const char* argv[])
{
	readFromStdInput();
	
	return 0;
}
