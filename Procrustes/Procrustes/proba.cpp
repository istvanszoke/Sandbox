#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;


vector<Mat> readFromStdInput()
{
	string temp;
	
	
	while (cin >> temp)
	{
		
		if (temp[0] == '{')
		{
			int vector_count, dim;
			cin >> vector_count >> dim;
			Mat sample(40, 2, CV_32FC2);
			while (temp[0] != '}')
			{
				
			}
		}
	}
}


int main(int argc, const char* argv[])
{
	readFromStdInput();
}
