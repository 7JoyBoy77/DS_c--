#include <iostream>
#include <string>
using namespace std;
class GamePeople
{
    friend GamePeople HBlood(GamePeople gp);

private:
    int blood_volume = 100;
    string name = "sb";
    unsigned power = 100;

public:
    GamePeople() = default;
    GamePeople(int bv, string custon_name, unsigned custom_power) : blood_volume(bv), name(custon_name), power(custom_power)
    {
    }
    int HealBlood() { return blood_volume; }
};
int main()
{
    return 0;
}
