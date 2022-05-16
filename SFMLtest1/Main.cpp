#include <iostream>
#include "Calculator.h"
#include "Button.h"

//using namespace sf;

int main()
{
    //Init Calculator engine
    Calculator calc;
    
    //Calculator loop
    while (calc.running())
    {
        //Update
        calc.update();

        //Render
        calc.render();
    }

    //End of application
    return 0;
}