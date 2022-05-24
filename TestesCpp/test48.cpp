#include <unordered_map>
#include <iostream>
#include <string>

enum class Component
{
    XX,
    YY,
    ZZ,
    XY,
    YX,
    XZ,
    ZX,
    YZ,
    ZY,
    WD //without direction. For scalar variables
};

enum class Variable
{
    SECOND_PIOLA_KIRCHHOFF_STRESS,
    GREEN_STRAIN,
    CAUCHY_STRESS,
    ENGINEERING_STRAIN,
    FIRST_PIOLA_KIRCHHOFF_STRESS,
    DAMAGE,
    PLASTIC_STRESS,
    PLASTIC_STRAIN,
    DISPLACEMENT,
    TOTAL_NUMBER_VARIABLES //Total number of variables. If necessary add more BEFORE this last name.
};

struct DoFType
{
public:
    Variable name;
    Component component;

    DoFType(Variable varName = Variable::TOTAL_NUMBER_VARIABLES, Component varComponent = Component::WD)
    : name(varName), component(varComponent)
    {}

    //copy constructor
    DoFType(const DoFType& DoFType)
    : name(DoFType.name), component(DoFType.component)
    {}

    DoFType& operator=(const DoFType& DoFType)
    {
        if (this == &DoFType)
        return *this;

        // do the copy
        name = DoFType.name;
        component = DoFType.component;

        // return the existing object so we can chain this operator
        return *this;
    }

    bool operator==(const DoFType &other) const;

    // void print() const
    // {   
    //     std::string varName;
    //     switch (name)
    //     {
    //     case Variable::DISPLACEMENT :
    //         varName = "d";
    //         break;
    //     case Variable::TOTAL_NUMBER_VARIABLES : 
    //         throw std::invalid_argument("Invalid");
    //         break;
    //     }
    //     std::string varComp;
    //     switch (component)
    //     {
    //     case Component::XX :
    //         varComp = "x";
    //         break;
    //     case Component::YY :
    //         varComp = "y";
    //         break;
    //     case Component::ZZ :
    //         varComp = "z";
    //         break;
    //     }

    //     std::cout << varName+varComp << std::endl;
    // }
};

namespace std
{
    template<> struct hash<DoFType>
    {
        std::size_t operator()(DoFType const& dofType) const noexcept;
    };
}

int main()
{
    DoFType dofType;

    std::string gdofType = "dy";
    if(gdofType == "dx")
    {   
        dofType = DoFType(Variable::DISPLACEMENT, Component::XX);
    }
    else
    if(gdofType == "dy")
    {
        dofType = DoFType(Variable::DISPLACEMENT, Component::YY);
    }
    else
    if(gdofType == "dz")
    {
        dofType = DoFType(Variable::DISPLACEMENT, Component::ZZ);
    }

    dofType.print();
}

