#include "BitcoinExchange.hpp"

static bool isLeapYear(unsigned int Year)
{
    if (Year % 400 == 0)
        return true;
    if (Year % 100 == 0)
        return false;
    return (Year % 4 == 0);
}

static int daysInMonth(unsigned int Month, unsigned int Year)
{
    if (Month == 2)
        return isLeapYear(Year) ? 29 : 28;

    if (Month == 4 || Month == 6 || Month == 9 || Month == 11)
        return 30;

    return 31;
}

static bool valid_date(unsigned int Year, unsigned int Month, unsigned int Date)
{
    if (Month < 1 || Month > 12)
        return false;
    if (Date < 1 || Date > (unsigned int)daysInMonth(Month, Year))
        return false;
    return true;
}

static bool valid_value(const std::string &Value)
{
    try
    {
        float v = std::stof(Value);
        if (v < 0)
            return (std::cerr << "Error: not a positive number.\n", false);
        if (v > 1000)
            return (std::cerr << "Error: value out of range.\n", false);
    }
    catch (...)
    {
        return (std::cerr << "Error: invalid number.\n", false);
    }
    return true;
}


static bool valid_data(const std::string &y, const std::string &m,
                const std::string &d, const std::string &Value)
{
    try
    {
        unsigned int Year = std::stoi(y);
        unsigned int Month = std::stoi(m);
        unsigned int Date = std::stoi(d);

        if (Year > 2026 || !valid_date(Year, Month, Date))
            return (std::cerr << "Error: bad input => "
                    << y << "-" << m << "-" << d << "\n", false);

        if (!valid_value(Value))
            return (false);
    }
    catch (...)
    {
        return (std::cerr << "Error: bad input format\n", false);
    }
    return true;
}

static bool line_parsing(const std::string &line)
{
    size_t pos_pipe = line.find('|');
    size_t pos_dash1 = line.find('-');
    size_t pos_dash2 = line.rfind('-');

    if (pos_pipe == std::string::npos ||
        pos_dash1 == std::string::npos ||
        pos_dash2 == std::string::npos)
        return (std::cout << "Error: bad input => " << line << "\n", false);

    std::string Year  = line.substr(0, pos_dash1);
    std::string Month = line.substr(pos_dash1 + 1, pos_dash2 - pos_dash1 - 1);
    std::string Date  = line.substr(pos_dash2 + 1, pos_pipe - pos_dash2 - 1);
    std::string Value = line.substr(pos_pipe + 1);

    return valid_data(Year, Month, Date, Value);
}

bool file_pasing(char *argv)
{
    std::ifstream file(argv);
    if(!file.is_open())
        return(std::cerr << "Failed to open file\n", false);
    std::string line;
    if (!std::getline(file, line))
        return (std::cerr << "Error: empty file\n", false);

    if (line != "date | value")
        return (std::cerr << "Error: invalid header\n", false);
    while(std::getline(file, line))
    {
        if (line_parsing(line))
            std::cout << line << "\n";
    }
    file.close();
    return(true);
}
