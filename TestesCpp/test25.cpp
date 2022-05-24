#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
// #include <boost/filesystem.hpp>



void plotResidualNorm(std::vector<double>residualHistory, bool last = false)
{
    // std::string path = "./TestesCpp";
    // std::string foldername = "OutputFiles";
    
    // std::string currentpath = path + "/" + foldername;
    // boost::filesystem::create_directories(currentpath);
    // std::string name = currentpath + "/" + filename + ".csv";
    static int count = 0;

    static std::stringstream residualHistoryStream;
    if(count==0)
    {
        residualHistoryStream << "accumulativeIterationNumer," << "residualValue" << std::endl;
    }
    
    std::cout << "Writing..." << std::endl;
    for(int i = 0; i < residualHistory.size(); ++i)
    {
        residualHistoryStream << count << "," << residualHistory[i] << std::endl;
        ++count;
    }

    if(last)
    {
        std::string filename = "residualHistory";
        std::fstream output_file;
        output_file.open(filename, std::ios::out);
        if (output_file.is_open())
        {  
            output_file << residualHistoryStream.str();
        }
        output_file.close();
        residualHistoryStream.str(std::string());
        count = 0;
    }
    
}

int main()
{
    
    
    std::vector <double> vec(3,100);
    plotResidualNorm(vec);
    std::vector <double> vec2(3,200);
    plotResidualNorm(vec2,true);
    std::vector <double> vec3(3,300);
    plotResidualNorm(vec3);
    std::vector <double> vec4(3,400);
    plotResidualNorm(vec4,true);
    
}