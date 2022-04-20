#include "PESELValidator.hpp"

bool PESELValidator::validatePESEL(const std::string &PESEL) const noexcept
{
    if (validatePESELSize(PESEL) == false)
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
    if (validatePESELDate(PESEL) == false)
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
    if (validateControlNumber(PESEL) == false)
    {
        std::cout << "PESEL is invalid" << std::endl;
        return false;
    }
    std::cout << "PESEL is valid" << std::endl;
    return true;
}

bool PESELValidator::validatePESELSize(const std::string &PESEL) const noexcept
{
    if (PESEL.size() != 11)
    {
        return false;
    }
    return true;
}

bool PESELValidator::validatePESELDate(const std::string &PESEL) const noexcept
{
    std::string Month = PESEL.substr(2, 2);
    std::string Day = PESEL.substr(4, 2);

    if (std::stoi(Month) < 1 && std::stoi(Month) > 12)
    {
        return false;
    }
    if (std::stoi(Month) == 2 && (std::stoi(Day) < 1 || std::stoi(Day) > 29))
    {
        return false;
    }
    if ((std::stoi(Month) == 4 || std::stoi(Month) == 6 || std::stoi(Month) == 9 || std::stoi(Month) == 11) && (std::stoi(Day) < 1 || std::stoi(Day) > 30))
    {
        return false;
    }
    if ((std::stoi(Month) == 1 || std::stoi(Month) == 3 || std::stoi(Month) == 5 || std::stoi(Month) == 7 || std::stoi(Month) == 8 || std::stoi(Month) == 10 || std::stoi(Month) == 12) && (std::stoi(Day) < 1 && std::stoi(Day) > 31))
    {
        return false;
    }
    return true;
}

bool PESELValidator::validateControlNumber(const std::string &PESEL) const noexcept
{
    std::vector<int> weights{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::transform(begin(weights), end(weights), begin(PESEL), begin(weights),
                   [](auto weight, auto PESELNumber)
                   { return weight * (PESELNumber - '0'); });
    std::string tempStr = std::to_string(std::accumulate(begin(weights), end(weights), 0));
    int controlNumber = 10 - (tempStr.back() - '0');
    if(controlNumber == 10)
    {
        controlNumber = 0;
    }

    if (controlNumber != (PESEL.back() - '0'))
    {
        return false;
    }
    return true;
}