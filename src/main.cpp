#include "pch.h"

#include "utils/math.h"
#include "timer.h"

int main()
{
    using namespace std;
    Timer timer;

    while (true)
    {
        timer.update();

        cout << timer.dt() << endl;
    }

    return 0;
}
