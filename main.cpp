#include <iostream>
#include "System/Sys.h"

using namespace std;

int main()
{
    Sys *sys = new Sys(); // Create a new system.
    sys -> run(); // Run the system.
    return 0;
}