#include "pch.h"

#include "utils/timer.h"
#include "utils/math.h"

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
