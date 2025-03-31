#include <iostream>
#include <fstream>
#include <iomanip> 




 double map( double x) {
	double a = 3;
    double b = 4;
	double c = 7;

	double y =  x*(a/b) - c/b;
	
	return y; 
}

int main()
{
	std::ifstream data("./data.txt");
	
	if(data.fail())
	{
		std::cerr << "Non è stato possibile aprire file" << std::endl;
		return 1;
	}
	
	std::ofstream ofs("./result.txt");
	ofs << std::setprecision(16) <<std::scientific;	


	ofs << "# N Mean"<< std::endl;

	
	double mean = 0;
	int i = 0;
	double somma = 0;
	double val;

	while(data >> val) {
		

		val = map(val);
		somma = somma + val; 
		mean = somma/(i+1);
		
		i++;

		ofs << i << " " << mean<< std::endl;
	}
	
	data.close();
	ofs.close();
	

    return 0;
}
