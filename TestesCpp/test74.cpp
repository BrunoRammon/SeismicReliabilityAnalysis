#include<iostream>
#include<vector>

int main()
{

    std::vector<int>gdof{3,2,5};
    int sizes = gdof[0]+gdof[1]+gdof[2];
    std::vector<double> mats(sizes*sizes,0.0);
    
    int count = 0;
    for(int iNode = 0; iNode < 3;++iNode)
    {
        for(int iGdof = 0; iGdof < gdof[iNode]; ++iGdof)
        {
            for(int jGdof = 0; jGdof < gdof[iNode];++jGdof)
            {
                mats[count] = count;
                ++count;
            }
            count +=(sizes-gdof[iNode]);
        }
        count += gdof[iNode];
    }

    for(int i = 0; i < sizes; ++i)
    {
        for(int j = 0; j < sizes; ++j)
        {
            std::cout << mats[i*sizes+j] << ", ";
        }
        std::cout << std::endl;
    }
}