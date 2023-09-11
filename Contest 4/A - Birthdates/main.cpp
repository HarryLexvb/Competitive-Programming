#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>


struct Person // struct to store person's information
{
    std::string name;
    int day{};
    int month{};
    int year{};
};

bool compare(const Person& a, const Person& b) //function to compare two person by their age
{
    if (a.year != b.year)
        return a.year < b.year;
    else if (a.month != b.month)
        return a.month < b.month;
    else
        return a.day < b.day;
}

int main()
{
    int n; // number of people
    std::cin >> n;
    std::cin.ignore(); // ignore the newline character
    std::vector<Person> list; // vector to store the list of people
    for (int i = 0; i < n; ++i){ // input the list of people
        Person p;
        std::string s;
        getline(std::cin, s);
        std::stringstream ss(s);
        ss >> p.name >> p.day >> p.month >> p.year;
        list.push_back(p);
    }
    sort(list.begin(), list.end(), compare); // sort the list by age
    std::cout << list[n - 1].name << std::endl; // print the oldest person
    std::cout << list[0].name << std::endl; // print the youngest person
    return 0;
}