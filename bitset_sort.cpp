#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>



int main()
{

std::string path = "myfile.txt";

std::fstream fs;
const u_long number = 100000;
fs.open(path, std::fstream::in | std::fstream::out | std::fstream::app);

if(!fs.is_open())
{
    std::cout << "_____________ERROR____________" << std::endl;
}
else
{
    int command{};
    std::cout << "for pour numbers in file enter: 1" << std::endl;
    std::cout << "for read numbers in file enter: 2" << std::endl;

    std::cin >> command;
    if(command == 1)
    {
        size_t num_txt {};
        for(int i = 10000; i < number; ++i)
        {
            num_txt = rand() % number;
            fs << num_txt << std::endl;
        }
    }
    else if(command == 2)
    {
        std::string path2 = "myfile2.txt";
        std::fstream fs2;
        fs2.open(path2, std::fstream::in | std::fstream::out | std::fstream::app);
        std::bitset<number> v;
        std::string str ;
        while (!fs.eof())
        {
            str = "" ;
            fs >> str ;
            if( str != "" )
            {
                v[std::stoi(str)] = true ;
            }
        }
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i])
            {
                fs2 << i << std::endl;
            }
        }
        fs2.close();
    }
}
fs.close();

    return 0;
}