#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

int main()
{
    std::pair<std::string,std::vector<std::string>> recuperationFieldGroup1 = {"STRESS",{"Srxx","Sryy","Srxy"}};
    std::pair<std::string,std::vector<std::string>> recuperationFieldGroup2 = {"STRAIN",{"Erxx","Eryy","Erxy"}};
    std::pair<std::string,std::vector<std::string>> recuperationFieldGroup3 = {"STRAIN",{"AABB","Eryy","Erxy"}};

    std::unordered_map<std::string, std::vector<std::string>> umap;

    umap.insert(recuperationFieldGroup1);
    umap.insert(recuperationFieldGroup2);
    std::cout << umap["STRESS"][0] << std::endl;
    std::cout << umap["STRAIN"][0]<< std::endl;

    bool inserted = umap.insert(recuperationFieldGroup3).second;
    if(!inserted)
    {
        std::cout << "This key has already been inserted. Insert this key will overwrite the old one. Press enter to continue." << std::endl;
        std::cin.get();
        umap[recuperationFieldGroup3.first] = recuperationFieldGroup3.second;

    }
    std::cout << umap["STRESS"][0] << std::endl;
    std::cout << umap["STRAIN"][0]<< std::endl;

    inserted = umap.insert(recuperationFieldGroup2).second;
    if(!inserted)
    {
        std::cout << "This key has already been inserted. Insert this key will overwrite the old one. Press enter to continue." << std::endl;
        std::cin.get();
        umap[recuperationFieldGroup2.first] = recuperationFieldGroup2.second;

    }
    std::cout << umap["STRESS"][0] << std::endl;
    std::cout << umap["STRAIN"][0]<< std::endl;

}
