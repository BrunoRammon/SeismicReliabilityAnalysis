#include <cstdint>
#include <functional> // reference_wrapper
#include <iostream>
#include <string>
#include <vector>
 
// Since Doctor and Patient have a circular dependency, we're going to forward declare Patient
class Patient;
 
class Doctor
{
private:
	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patient{};
 
public:
	Doctor(const std::string& name);
 
	void addPatient(Patient& patient);
	
	// We'll implement this function below Patient since we need Patient to be defined at that point
	friend std::ostream& operator<<(std::ostream &out, const Doctor &doctor);
 
	const std::string& getName() const;
};
 
class Patient
{
private:
	std::string m_name{};
	const Doctor* m_doctor; // so that we can use it here
 
	// We're going to make addDoctor private because we don't want the public to use it.
	// They should use Doctor::addPatient() instead, which is publicly exposed
	// void addDoctor(const Doctor& doctor)
	// {
	// 	m_doctor.push_back(doctor);
	// }
 
public:
	Patient(const std::string& name, const Doctor* doctor);
 
	// We'll implement this function below Doctor since we need Doctor to be defined at that point
	friend std::ostream& operator<<(std::ostream &out, const Patient &patient);
 
	const std::string& getName() const;
    void changeName(const std::string& name);
 
	// We'll friend Doctor::addPatient() so it can access the private function Patient::addDoctor()
	friend void Doctor::addPatient(Patient& patient);
};

/*Doctor Definitions*/

Doctor::Doctor(const std::string& name)
: m_name{ name }
{}

std::ostream& operator<<(std::ostream &out, const Doctor &doctor)
{
	if (doctor.m_patient.empty())
	{
		out << doctor.m_name << " has no patients right now";
		return out;
	}
 
	out << doctor.m_name << " is seeing patients: ";
	for (const auto& patient : doctor.m_patient)
		out << patient.get().getName() << ' ';
 
	return out;
}

const std::string& Doctor::getName() const { return m_name; };

void Doctor::addPatient(Patient& patient)
{
	// Our doctor will add this patient
	m_patient.push_back(patient);
 
	// and the patient will also add this doctor
	// patient.addDoctor(*this);
}

/*Patient Definitions*/

Patient::Patient(const std::string& name, const Doctor* doctor)
: m_name{ name }, m_doctor{ doctor }
{}

std::ostream& operator<<(std::ostream &out, const Patient &patient)
{
	// if (patient.m_doctor.empty())
	// {
	// 	out << patient.getName() << " has no doctors right now";
	// 	return out;
	// }
 
	out << patient.m_name << " is seeing doctor: ";
	out << patient.m_doctor->getName() << ' ';
 
	return out;
}

const std::string& Patient::getName() const { return m_name; }

void Patient::changeName(const std::string& name)
{
    m_name = name;
}
 
// std::ostream& operator<<(std::ostream &out, const Patient &patient)
// {
// 	if (patient.m_doctor.empty())
// 	{
// 		out << patient.getName() << " has no doctors right now";
// 		return out;
// 	}
 
// 	out << patient.m_name << " is seeing doctors: ";
// 	for (const auto& doctor : patient.m_doctor)
// 		out << doctor.get().getName() << ' ';
 
// 	return out;
// }
 
int main()
{
	// Create a Patient outside the scope of the Doctor
    Doctor james{ "James" };
	Doctor scott{ "Scott" };

	Patient dave{ "Dave", &james };
	Patient frank{ "Frank", &scott };
	Patient betsy{ "Betsy", &scott };
 
	james.addPatient(dave);
 
	scott.addPatient(frank);
	scott.addPatient(betsy);
 
	std::cout << james << '\n';
	std::cout << scott << '\n';
	std::cout << dave << '\n';
	std::cout << frank << '\n';
	std::cout << betsy << '\n';

    frank.changeName("Franka");
    std::cout << frank << '\n';
    std::cout << scott << '\n';
	return 0;
}