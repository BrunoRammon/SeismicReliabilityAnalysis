#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <boost/container_hash/hash.hpp>


enum class test
{
    Srxx,
    Sryy,
    Srzz,
    Srxy,
    Srxz,
    Sryz
};

enum class variables
{
    SECOND_PIOLA_KIRCHHOFF_STRESS,
    GREEN_STRAIN,
    TOTAL_NUMBER_VARIABLES
};


enum class Component
{
    XX,
    YY,
    ZZ
};

struct DoFId
{
public:
    variables name;
    Component component;

    DoFId(variables varName, Component varComponent)
    : name(varName), component(varComponent)
    {}

    bool operator==(const DoFId &other) const
    { 
        return (name == other.name && component == other.component);
    }

    // size_t hash_value()
    // {
    //     size_t seed = 0;
    //     std::stringstream ss; ss << this;

    //     boost::hash_combine(seed, ss.str());
    //     return seed;
    // }
};

namespace std
{
    template<> struct hash<DoFId>
    {
        std::size_t operator()(DoFId const& dofId) const noexcept;
    };
}

std::size_t std::hash<DoFId>::operator()(DoFId const& dofId) const noexcept
{
    std::size_t h1 = static_cast<int>(dofId.name);
    std::size_t h2 = static_cast<int>(dofId.component)*static_cast<int>(variables::TOTAL_NUMBER_VARIABLES);
    return h1+h2; // or use boost::hash_combine
}

int main()
{

    std::unordered_map<variables, std::vector<test>> map;
    map[variables::SECOND_PIOLA_KIRCHHOFF_STRESS]={test::Srxx,test::Sryy,test::Srxy};


    for (test a : map[variables::SECOND_PIOLA_KIRCHHOFF_STRESS])
    {
        std::cout << static_cast<int>(a) << std::endl;
    }
    
    std::unordered_map<test,std::vector<double>>fieldMap;

    int  i = 0;
    for(test field : map[variables::SECOND_PIOLA_KIRCHHOFF_STRESS])
    {
        fieldMap[field] = std::vector<double>(4,i);
        ++i;
    }
    for(test field : map[variables::SECOND_PIOLA_KIRCHHOFF_STRESS])
    {
        for(int i = 0; i < fieldMap[field].size(); ++i)
            std::cout << fieldMap[field][i] << std::endl;
            
    }
    std::unordered_map<DoFId, double> map2;

    DoFId id1(variables::SECOND_PIOLA_KIRCHHOFF_STRESS,Component::XX);
    DoFId id2(variables::SECOND_PIOLA_KIRCHHOFF_STRESS,Component::YY);
    DoFId id3(variables::SECOND_PIOLA_KIRCHHOFF_STRESS,Component::ZZ);
    DoFId id4(variables::GREEN_STRAIN,Component::XX);
    DoFId id5(variables::GREEN_STRAIN,Component::YY);
    DoFId id6(variables::GREEN_STRAIN,Component::ZZ);

    std::cout <<  "Unique ID: " <<std::hash<DoFId>{}(id1) << std::endl;
    std::cout <<  "Unique ID: " <<std::hash<DoFId>{}(id4) << std::endl;
    std::cout <<  "Unique ID: " <<std::hash<DoFId>{}(id2) << std::endl;
    std::cout <<  "Unique ID: " <<std::hash<DoFId>{}(id5) << std::endl;
    std::cout <<  "Unique ID: " <<std::hash<DoFId>{}(id3) << std::endl;    
    std::cout <<  "Unique ID: " <<std::hash<DoFId>{}(id6) << std::endl;

    map2[id1] = 0.53;
    map2[id2] = 0.73;
    map2[id3] = 0.95;
    map2[id4] = 0.78;
    map2[id5] = 0.42;
    map2[id6] = 0.49;

    for (auto& pair : map2)
    {
        std::cout <<  "Value: " << pair.second << std::endl;
    }

    DoFId id7(variables::TOTAL_NUMBER_VARIABLES,Component::ZZ);
    std::cout <<  "Value: " << map2.at(id7) << std::endl;
}
