#include "BitcoinExchange.hpp"

static std::map<std::string, float> g_db;

static bool isLeapYear(unsigned int Year)
{
    return (Year % 400 == 0)
        || (Year % 4 == 0 && Year % 100 != 0);
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
        if (Value.empty())
            return(std::cerr << "Error: You must put a value.\n", false);
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

        if (Year < 2009 || Year > 2022)
            return (std::cerr << "Error: Year in data base from 2009 to 2022\n", false);
        if (!valid_date(Year, Month, Date))
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

bool get_rate(const std::string &date, float &rate)
{
    auto it = g_db.lower_bound(date); //Finds the beginning of a subsequence matching given key.  
                                    //auto is std::map<std::string, float>::iterator

    if (it != g_db.end() && it->first == date) //if date exist set rate to it 
                                                // if you reach .end that mean tha there is no exact date in pool
    {
        rate = it->second;
        return true;
    }
    if (it == g_db.begin()) //its a first accurance so no smaller date exist, cant get a smallerrate 
        return false;

    --it; // take smaller(previous rate)
    rate = it->second;
    return true;
}

static bool line_parsing(const std::string &line)
{
    size_t pos_char = line.find('|');
    size_t pos_dash1 = line.find('-');
    size_t pos_dash2 = line.rfind('-');

    if (pos_char == std::string::npos || pos_dash1 == std::string::npos || pos_dash2 == std::string::npos)
    {
        return(std::cerr << "Error: bad input => " << line << "\n", false);
    }

    std::string Year  = line.substr(0, pos_dash1);
    std::string Month = line.substr(pos_dash1 + 1, pos_dash2 - pos_dash1 - 1);
    std::string Date  = line.substr(pos_dash2 + 1, pos_char - pos_dash2 - 1);
    std::string Value = line.substr(pos_char + 1);

    if (!valid_data(Year, Month, Date, Value))
        return false;

    float fValue = std::stof(Value); //dont need trycatch bc we did it in valid_data
    int y = std::stoi(Year);
    int m = std::stoi(Month);
    int d = std::stoi(Date);

    std::string full_date =
        std::to_string(y) + "-" +
        (m < 10 ? "0" : "") + std::to_string(m) + "-" +
        (d < 10 ? "0" : "") + std::to_string(d);

    float rate;
    if (!get_rate(full_date, rate))
    {
        std::cerr << "Error: no earlier date for " << full_date << "\n";
        return false;
    }

    std::cout << full_date << " => " << fValue << " * " << rate 
              << " = " << fValue * rate << "\n";
    return true;
}

bool file_parsing(char *argv)
{
    std::ifstream file(argv);
    if(!file.is_open())
        return(std::cerr << "Failed to open file\n", false);
    std::string line;
    if (!std::getline(file, line))
        return (std::cerr << "Error: empty file\n", false);

    if (line != "date | value")
        return (std::cerr << "Error: invalid header in input file\n", false);
    while(std::getline(file, line))
    {
       line_parsing(line);
    }   
    file.close();
    return(true);
}


bool data_file_parsing(std::string Data_File)
{
    std::ifstream file(Data_File);
    if(!file.is_open())
        return(std::cerr << "Error: cant open Data file\n", false);
    std::string line;
    if (!std::getline(file, line))
        return (std::cerr << "Error: empty file\n", false);
    if (line != "date,exchange_rate")
        return (std::cerr << "Error: invalid header in data file\n", false);
    while(std::getline(file, line))
    {
        size_t pos = line.find(',');  //find , in string
        if (pos == std::string::npos)
            continue;
        std::string date = line.substr(0, pos); // date == from 0 to pos of ','
        try {
            float rate = std::stof(line.substr(pos + 1));
            g_db[date] = rate;  // soo here we put map<str, float> (map<key, value>) so it looks like map<date, rate>
        } catch (...)
        {
            return (std::cerr << "Error: Data_file bad input\n", false);            
        }
    }
    return(true);
}