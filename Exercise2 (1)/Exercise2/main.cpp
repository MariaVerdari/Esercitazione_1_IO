#include <iostream>
#include <fstream>
#include <iomanip> 
#include <numbers>
#include <cmath>






double map(double x) {
	

	double y =  x*(double(3)/double(4)) - double(7)/double(4);
	
	return y; 
}

int main()
{
	std::ifstream data("./data.txt");
	std::ofstream ofs("./result.txt");
	ofs<< std::setprecision(16) <<std::scientific;	

	

	ofs << "# N Mean"<< "\n";


	if(data.fail())
	{
		std::cerr << "Non è stato possibile aprire file" << std::endl;
		return 1;
	}
	
	double mean = 0;
	int i = 0;
	double val;

	while(data >> val) {

		val = map(val);

		mean = (mean*i + val)/(i+1);
		
		i++;
		ofs << mean<< "\n";
	}
	
	data.close();
	ofs.close();
	

    return 0;
}
